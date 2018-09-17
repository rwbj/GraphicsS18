//nascent proof of concept for distibuted scrabble-like game, not
//complete by any means, lots of debug code, some known bugs... but does prove the concept
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import java.util.Arrays;
import java.util.Random;

public class Board3 extends JFrame implements ActionListener, MouseListener{
	Random srnd = null;
	Toolkit toolkit=null;
	ImageIcon[] icotile, icotilesq, icoboard;
	JLabel top, lturn, ltime;
	JLabel[] tiles, brd, filler, pi;
	int[] itiles, ibrd=null;
	TurnMetric[] pidata;
	JButton shuffle, reset, send, start;
	JTextArea chat;
	JTextField cline;
	String trck, tbrd, name;
	JPanel p;
	Timer tm;
	int which, remainingtime, timeperturn=60,turn=0, pcnt=0;
	Proto wme=null;
	byte[] nulls, cmd;
	static final int MAXPLAYERS=4;
	Cursor startCurse, tileCurse;
	Point ulc;			//upper left screen coord of board[0]
	volatile String agmsg;

	void setWatcher(Proto p) {
		wme=p;
	}


	void setTiles(String sb, JLabel[] gb) {
		for (int i=0; i<sb.length(); i++) {
			gb[i].setIcon(icotile[sb.charAt(i) - 'a']);
			gb[i].setVisible(true);
			gb[i].setEnabled(true);
		}
	}


	void setBoard(String sb, JLabel[] gb) {
System.out.println("in setboard, sb = " + sb);

		for (int i=0; i<sb.length(); i++)
			gb[i].setIcon(icoboard[sb.charAt(i) - ' ']);
	}




    public void mousePressed(MouseEvent e) {

saySomething("Mouse pressed; # of clicks: "
                    + e.getClickCount(), e);

		int x0,y0,x1,y1;
		which= -1;
		for (int i=0; i<tiles.length; i++)  {
			if (e.getComponent() == tiles[i]) {
				which=i;
				break;
			}
		}

		x0=e.getX();  y0=e.getY();
		x1=e.getXOnScreen();  y1=e.getYOnScreen();
		ImageIcon ii = (ImageIcon) tiles[which].getIcon();
		tileCurse = toolkit.createCustomCursor(ii.getImage() , new Point(x0,y0), "img");
		setCursor(tileCurse);
		tiles[which].setEnabled(false);

System.out.printf("which= %d  x1-x0 =  %d\n", which, x1-x0);
		ulc.x = (x1-x0) - (which * tiles[0].getWidth());
		ulc.y = tiles[0].getHeight()+(y1-y0);

System.out.printf("x0 = %d  y0 = %d   x1= %d  y1= %d\n", x0,y0,x1,y1);
System.out.println("ulc = " + ulc.x + " " + ulc.y);

if (e.getComponent() == tiles[1])
System.out.println("yes to 0");
else
System.out.println("no to 0");

    }

    public void mouseReleased(MouseEvent e) {
		int x,y,bidx;

		x=e.getXOnScreen();
		y=e.getYOnScreen();
		setCursor(startCurse);

		if ((y >= ulc.y) && (y <= (ulc.y + brd[0].getHeight()))) {
			bidx = (x-ulc.x)/brd[0].getWidth();
			if ((bidx>=0) && (bidx<brd.length) && (ibrd[bidx] == 0)) {
				System.out.println("yes to brd " + bidx);
				brd[bidx].setIcon(tiles[which].getIcon());
				ibrd[bidx]=which+1;
				tiles[which].setVisible(false);
				itiles[which]=0;
				return;
			}
		}
		tiles[which].setEnabled(true);
    }

    public void mouseEntered(MouseEvent e) {
    }

    public void mouseExited(MouseEvent e) {
    }

    public void mouseClicked(MouseEvent e) {
    }

    void saySomething(String eventDescription, MouseEvent e) {
System.out.println("MOUSE: " + eventDescription);
    }










	//implements protocol with the server after initial handshake
	void processMessage(String m) {
		agmsg = new String(m);

//GUIs are not thread-safe
/*
		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
*/

System.out.println(">>>>>>>>>>>>>got " + agmsg);
				if (agmsg.compareTo("state=NOTREADY") == 0) {cline.setText("waiting for server"); return; }
				if (agmsg.compareTo("state=READY") == 0) {cline.setText("waiting for start"); return; }



//needs to be factored out, but each if handles a message
				if (agmsg.startsWith("plist=")) {
					int bi=agmsg.indexOf('=');
					int ei=agmsg.indexOf(' ');
					bi++;
					String starter = agmsg.substring(bi,ei);
					String playerList = agmsg.substring(bi);
					String[] plist = playerList.split(" ");
					for (int i=0; i<plist.length; i++) {
						if (i<pi.length)
							if (plist[i].length() < 10)
								pi[i].setText((i+1) + ". " + plist[i]);
							else
								pi[i].setText((i+1) + ". " + plist[i].substring(0,10));
						pcnt++;
					}

					if (name.compareTo(starter) == 0) {
						start.setVisible(true);
						cline.setText("click start to begin play");

System.out.println("I AM the starter");
					} else {
						cline.setText("waiting for " + starter + " to start the game");
System.out.println("SOMEBODY ELSE is the strater");
					return;
					}
				}





				//if there are fewer than 5 people playing, display them
				//else if I'm in the top 4 display the top 4
				//else display the top 3, then me as the 4th
				//
				if (agmsg.startsWith("scores=")) {
System.out.println("SCORES=");
					int myi=0,ub;

					//pick the message apart
System.out.println("SCORES= " + agmsg);
					String[] slist = agmsg.split(" ");
System.out.println("slist length =  " + slist.length);
for (int uy=0; uy<slist.length; uy++)
System.out.printf("slist[%d] = %s\n", uy, slist[uy]);


					int playercnt = (slist.length-1)/4;
System.out.println("playercnt =  " + playercnt);
					pidata = new TurnMetric[playercnt];


					//get sorted list of results
					for (int z=0; z<pidata.length; z++) {
System.out.println("z = " + z);
						pidata[z] = new TurnMetric();
						pidata[z].name = slist[1+(z*5)];
						pidata[z].last = Integer.parseInt(slist[3+(z*5)]);
						pidata[z].total = Integer.parseInt(slist[4+(z*5)]);
						pidata[z].lastw = new String(slist[5+(z*5)]);
					}
for (int w=0; w<pidata.length; w++) System.out.println("pre " + pidata[w].name + " " + pidata[w].total + " " + pidata[w].last);
					Arrays.sort(pidata);
for (int w=0; w<pidata.length; w++) System.out.println("post " + pidata[w].name + " " + pidata[w].total + " " + pidata[w].last);


					//figure out what to display
					for (int z=0; z<playercnt; z++) {
						if (pidata[z].name.compareTo(name) == 0)  myi=z;	// find myself
System.out.printf("finding myself, compare %d %s with %s\n", z, pidata[z].name, name);
					}


					if (playercnt <= pi.length)
						ub=playercnt;
					else
						if (myi < pi.length) { 
							ub=pi.length;
						} else {
							ub = pi.length-1;
							pi[pi.length-1].setText(pidata[myi].total + " " + pidata[myi].name +  " " + pidata[myi].lastw);
						}
System.out.println("upper bound is: " + ub + "       myi = " + myi);

					for (int z=0; z<ub; z++) 
						pi[z].setText(pidata[z].total + " " + pidata[z].name +  " " + pidata[z].lastw);
				}




				if (agmsg.startsWith("chat=")) {
					String rest = agmsg.substring(5);
					String source = rest.substring(0,5);
					String msg = rest.substring(5);
					return;
				}

				if (agmsg.startsWith("peer=")) {
					int bi=agmsg.indexOf('=');
					bi++;
					String peer = agmsg.substring(bi);
					if (pcnt < pi.length) {
						if (peer.length() < 10)
							pi[pcnt].setText((pcnt+1) + ". " + peer);
						else
							pi[pcnt].setText((pcnt+1) + ". " + peer.substring(0,10));
						pcnt++;
					}
					return;
				}

				if (agmsg.startsWith("turn=")) {

					if (turn==0) cline.setText("chat: ");

					int ti = agmsg.indexOf('=');
					int tb = agmsg.indexOf(',');
					String tnum = agmsg.substring(ti+1,tb);
					turn = Integer.parseInt(tnum);
System.out.printf("turn is %d\n", turn);
					lturn.setText("turn:  " + turn);
					remainingtime = timeperturn;
					ltime.setText("time:  " + remainingtime);
					if (! tm.isRunning()) tm.start();

					int bi = agmsg.indexOf('/');
					tbrd = agmsg.substring(bi+1, bi+8);

					int ri = agmsg.indexOf('|');
					trck = agmsg.substring(ri+1, ri+8);

					setTiles(trck, tiles);
					setBoard(tbrd, brd);
					Arrays.fill(itiles, 1);
					Arrays.fill(ibrd, 0);

System.out.printf("BOARD: %s       RACK: %s\n", tbrd, trck);
				}
 //turn=1,board=& $$&$$*$  %   ,rack=odtxrsc


				if (agmsg.compareTo("error=COMMUNICATIONS") == 0) {
					JOptionPane.showMessageDialog(null, "communication with server failed - sorry", "fatal error :(", JOptionPane.ERROR_MESSAGE);
					System.exit(2);
				}
				if (agmsg.compareTo("error=SERVERCLOSE") == 0) {
					JOptionPane.showMessageDialog(null, "server was working, then it died - sorry", "fatal error :(", JOptionPane.ERROR_MESSAGE);
					System.exit(1);
				}
/*
			}
		});
*/
	}

	public Board3() {
		int i;
		Color bc, bkc;
		BufferedReader br;
		Font f14p, f18p;

		remainingtime = timeperturn;
		srnd = new Random((long) 3);
		ulc = new Point(0,0);
		f14p = new Font("snap ITC", Font.PLAIN, 14);
		f18p = new Font("snap ITC", Font.PLAIN, 18);
		bc = new Color(239,228,176);
		bkc = new Color(49,49,49);
		top = new JLabel(new ImageIcon("img/topic.png"));


		icotile = new ImageIcon[27];
		icotilesq = new ImageIcon[27];
		icoboard = new ImageIcon[7];
		itiles = new int[7];
		Arrays.fill(itiles, 1);
		tiles = new JLabel[7];
		ibrd=new int[7];
		Arrays.fill(ibrd, 0);
		brd = new JLabel[7];
		filler = new JLabel[14];
		pi = new JLabel[MAXPLAYERS];
		for (i=0; i<4; i++) { pi[i] = new JLabel("   ", SwingConstants.CENTER); pi[i].setFont(f18p); pi[i].setForeground(bkc);}
		lturn = new JLabel("turn: ", SwingConstants.CENTER); lturn.setFont(f14p); lturn.setForeground(bkc);
		ltime = new JLabel("time: ", SwingConstants.CENTER); ltime.setFont(f14p); ltime.setForeground(Color.BLUE);


		//letter tiles
		for (i=0; i<icotile.length-1; i++) {
			String fname;

			fname = String.format("img/%cro.png", ('A'+i));
			icotile[i] = new ImageIcon(fname);
			fname = String.format("img/%cqb.png", ('A'+i));
			icotilesq[i] = new ImageIcon(fname);
		}
		icotile[icotile.length-1] = new ImageIcon("img/Bla.png");
		icotilesq[icotile.length-1] = new ImageIcon("img/Bls.png");


		//board squares
		icoboard[6] = new ImageIcon("img/Bdl.png");
		icoboard[5] = new ImageIcon("img/Bdw.png");
		icoboard[4] = new ImageIcon("img/Btl.png");
		icoboard[3] = new ImageIcon("img/Btw.png");
		icoboard[2] = new ImageIcon("img/Bql.png");
		icoboard[1] = new ImageIcon("img/Bqw.png");
		icoboard[0] = new ImageIcon("img/Bblank.png");


		for (i=0; i<tiles.length; i++)
			tiles[i] = new JLabel(new ImageIcon("img/bla.png"));

		for (i=0; i<brd.length; i++)
			brd[i] = new JLabel(new ImageIcon("img/Bbl.png"));

		for (i=0; i<filler.length; i++)
			filler[i] = new JLabel(new ImageIcon("img/filler.png"));

		//shuffle = new JButton("sh");
		shuffle = new JButton(new ImageIcon("img/shuffle0.png"));
		shuffle.setOpaque(false);
		shuffle.setContentAreaFilled(false);
		shuffle.setBorderPainted(false);
		shuffle.addActionListener(this);
		shuffle.setActionCommand("shuffle");

		reset = new JButton(new ImageIcon("img/reset0.png"));
		reset.setOpaque(false);
		reset.setContentAreaFilled(false);
		reset.setBorderPainted(false);
		reset.addActionListener(this);
		reset.setActionCommand("reset");

		send = new JButton(new ImageIcon("img/send0.png"));
		send.setOpaque(false);
		send.setContentAreaFilled(false);
		send.setBorderPainted(false);
		send.addActionListener(this);
		send.setActionCommand("send");

		start = new JButton(new ImageIcon("img/start0.png"));
		start.setOpaque(false);
		start.setContentAreaFilled(false);
		start.setBorderPainted(false);
		start.setVisible(false);
		start.addActionListener(this);
		start.setActionCommand("start");

		chat = new JTextArea("1234567890\n12345678901234567890\n\n\n\n\n\n123456789012345678901234567890\n",16,40);
		cline = new JTextField("waiting for server");



		startCurse = Cursor.getDefaultCursor();
		toolkit = Toolkit.getDefaultToolkit();
		//Image image = toolkit.getImage("img/Bla.png");

		p = new JPanel();
		this.add(p);
		p.setBackground(bc);
		GridBagLayout gridbag = new GridBagLayout();
		GridBagConstraints c = new GridBagConstraints();
		p.setLayout(gridbag);
		p.setFont(new Font("snap ITC", Font.PLAIN, 14));
c.anchor=GridBagConstraints.CENTER;

		c.gridx=0; c.gridy=0; c.gridwidth=16; c.gridheight=2;
		c.fill = GridBagConstraints.NONE;
		c.weightx = 0.0;
		gridbag.setConstraints(top, c);
		p.add(top);


for (int z=0; z<tiles.length; z++) tiles[z].addMouseListener(this);

		c.fill = GridBagConstraints.REMAINDER;
		c.gridx=0; c.gridy=2; c.gridwidth=1; c.gridheight=1; c.anchor=GridBagConstraints.CENTER;
		gridbag.setConstraints(filler[6], c);p.add(filler[6]);

		c.gridx=1; c.gridy=2; c.gridwidth=14; c.gridheight=1;
		gridbag.setConstraints(pi[0], c);p.add(pi[0]);

		c.gridx=15; c.gridy=2; c.gridwidth=1; c.gridheight=1;
		gridbag.setConstraints(filler[7], c);p.add(filler[7]);



		c.gridx=0; c.gridy=3; c.gridwidth=1; c.gridheight=1;
		gridbag.setConstraints(filler[8], c);p.add(filler[8]);

		c.gridx=1; c.gridy=3; c.gridwidth=14; c.gridheight=1;
		gridbag.setConstraints(pi[1], c); p.add(pi[1]);

		c.gridx=15; c.gridy=3; c.gridwidth=1; c.gridheight=1;
		gridbag.setConstraints(filler[9], c);p.add(filler[9]);



		c.gridx=0; c.gridy=4; c.gridwidth=1; c.gridheight=1;
		gridbag.setConstraints(filler[10], c);p.add(filler[10]);

		c.gridx=1; c.gridy=4; c.gridwidth=14; c.gridheight=1;
		gridbag.setConstraints(pi[2], c); p.add(pi[2]);

		c.gridx=15; c.gridy=4; c.gridwidth=1; c.gridheight=1;
		gridbag.setConstraints(filler[11], c);p.add(filler[11]);



		c.gridx=0; c.gridy=5; c.gridwidth=1; c.gridheight=1;
		gridbag.setConstraints(filler[12], c);p.add(filler[12]);

		c.gridx=1; c.gridy=5; c.gridwidth=14; c.gridheight=1;
		gridbag.setConstraints(pi[3], c); p.add(pi[3]);

		c.gridx=15; c.gridy=5; c.gridwidth=1; c.gridheight=1;
		gridbag.setConstraints(filler[13], c);p.add(filler[13]);





		
		c.weighty = c.weightx = 0.0;
		c.gridx=0; c.gridy=6; c.gridwidth=1; c.gridheight=1;  c.anchor=GridBagConstraints.WEST;
		c.fill = GridBagConstraints.BOTH;
		gridbag.setConstraints(filler[0], c); p.add(filler[0], c);
		for (i=0; i<tiles.length; i++) {
			c.gridx=1+(i<<1); c.gridy=6; c.gridwidth=2; c.gridheight=1;
			c.fill = GridBagConstraints.BOTH;
			gridbag.setConstraints(tiles[i], c);
			p.add(tiles[i]);
		}
		c.gridx=15; c.gridy=6; c.gridwidth=1; c.gridheight=1;
		c.fill = GridBagConstraints.BOTH;
		gridbag.setConstraints(filler[1], c); p.add(filler[1], c);


		c.gridx=0; c.gridy=7; c.gridwidth=1; c.gridheight=1;
		c.fill = GridBagConstraints.BOTH;
		gridbag.setConstraints(filler[2], c); p.add(filler[2], c);
		p.add(filler[2], c);
		for (i=0; i<brd.length; i++)  {
			c.gridx=1+(i<<1); c.gridy=7; c.gridwidth=2; c.gridheight=1;
			c.fill = GridBagConstraints.BOTH;
			gridbag.setConstraints(brd[i], c);
			p.add(brd[i]);
		}
		c.gridx=15; c.gridy=7; c.gridwidth=1; c.gridheight=1;
		c.fill = GridBagConstraints.BOTH;
		gridbag.setConstraints(filler[3], c); p.add(filler[3], c);



		c.gridx=0; c.gridy=8; c.gridwidth=1; c.gridheight=1;
		c.fill = GridBagConstraints.BOTH;
		gridbag.setConstraints(filler[4], c); p.add(filler[4], c);

		c.gridx=1; c.gridy=8; c.gridwidth=4; c.gridheight=1;
		c.fill = GridBagConstraints.BOTH;
		gridbag.setConstraints(shuffle, c); p.add(shuffle);

		c.gridx=5; c.gridy=8; c.gridwidth=4; c.gridheight=1;
		c.fill = GridBagConstraints.BOTH;
		gridbag.setConstraints(reset, c); p.add(reset);

		c.gridx=9; c.gridy=8; c.gridwidth=4; c.gridheight=1;
		c.fill = GridBagConstraints.BOTH;
		gridbag.setConstraints(send, c); p.add(send);

		c.gridx=13; c.gridy=8; c.gridwidth=3; c.gridheight=1;
		c.fill = GridBagConstraints.BOTH;
		gridbag.setConstraints(start, c); p.add(start, c);




		c.gridx=0; c.gridy=9; c.gridwidth=16; c.gridheight=32;
		c.fill = GridBagConstraints.VERTICAL;
		c.weighty=1.0;
		gridbag.setConstraints(chat, c); p.add(chat);
		



		c.gridx=0; c.gridy=41; c.gridwidth=8; c.gridheight=1; c.anchor=GridBagConstraints.CENTER;
		c.fill = GridBagConstraints.BOTH;
		gridbag.setConstraints(lturn, c); p.add(lturn);

		c.gridx=8; c.gridy=41; c.gridwidth=8; c.gridheight=1;
		c.fill = GridBagConstraints.BOTH;
		gridbag.setConstraints(ltime, c); p.add(ltime);




		c.gridx=0; c.gridy=42; c.gridwidth=16; c.gridheight=1;
		c.fill = GridBagConstraints.BOTH;
		c.weighty=0.0;
		gridbag.setConstraints(cline, c); p.add(cline);

		tm = new Timer(1000, this);
		tm.setActionCommand("timer");

		nulls = new byte[256];
		cmd = new byte[256];

		this.repaint();
		p.repaint();

	}






	String buildWord(int[] b) {
		int ccnt=0;
		char[] ca = new char[b.length];
		for (int i=0; i<b.length; i++) 
			if (b[i]>0) {
				ca[i] = trck.charAt(b[i]-1);
				ccnt++;
			} else {
				ca[i]=' ';
			}
			if (ccnt==0) return(null);
			for (int j=1; j<(b.length-1); j++)
				if ((ca[j] == ' ') && (ca[j-1] != ' ') && (ca[j+1] != ' ')) return(null); 
			return(new String(ca).trim());
	}


	boolean checkWord(String s) {
		return(true);
	}


	int firstLetter(int[] b){
		int r;
		for (r=0; r<b.length; r++)
			if (b[r]>0)
				return(r);
System.out.println("RED ALERT!!");
		return(0);
	}




	void sendMsg(String  m) {
		int i;
		byte[] b;
		try {
			b=m.getBytes("US-ASCII");
			for (i=0; i<b.length; i++) cmd[i] = b[i];
			for (i=0; i<4; i++) cmd[i] ^= wme.rnd[3-i];
			wme.bw.write(cmd, 0, b.length);
			wme.bw.write(nulls, 0, 256 - b.length);
			} catch (Exception err) {
			JOptionPane.showMessageDialog(null, "cannot send start message to server",
					"fatal error :(", JOptionPane.ERROR_MESSAGE);
			System.exit(1);
		}
	}




	public void actionPerformed(ActionEvent e) {
System.out.println("Action: " + e.getActionCommand());
		if (e.getActionCommand().compareTo("shuffle") == 0) {
			char tmp;
			int i,i1,i2;
			if (turn==0) return;
			char[] ca = trck.toCharArray();
			for (i=0; i<16; i++)  {
				i1 = srnd.nextInt(trck.length());
				i2 = srnd.nextInt(trck.length());
				tmp=ca[i1];
				ca[i1]=ca[i2];
				ca[i2]=tmp;
			}
			trck = new String(ca);
			setTiles(trck, tiles);
			setBoard(tbrd, brd);
			Arrays.fill(itiles, 1);
			Arrays.fill(ibrd, 0);
			return;
		}
		if (e.getActionCommand().compareTo("reset") == 0) {
			if (turn==0) return;
			setTiles(trck, tiles);
			setBoard(tbrd, brd);
			Arrays.fill(itiles, 1);
			Arrays.fill(ibrd, 0);
			return;
		}


		if (e.getActionCommand().compareTo("send") == 0) {
			byte[] bbb=null;

			if (turn==0) return;
			String ss = buildWord(ibrd);
			if (ss == null) {
				JOptionPane.showMessageDialog(null, "Invalid tile placement", "try again",
					JOptionPane.ERROR_MESSAGE);
				return;
			} else
				System.out.printf("send: " + ss);
			if (checkWord(ss)) {

				String sss =String.format("turn=%d,word=%s,ss=%d,", turn,ss,firstLetter(ibrd));
				sendMsg(sss);

			} else {
				JOptionPane.showMessageDialog(null, ss+" is not a valid word",
					"check the dictionary", JOptionPane.ERROR_MESSAGE);
				return;
			}
		}





		if (e.getActionCommand().compareTo("start") == 0) {
			sendMsg("start");
			cmd[0]='s'; cmd[1]='t'; cmd[2]='a'; cmd[3]='r'; cmd[4]='t'; 
			start.setVisible(false);
			lturn.setText("turn:  1");
			ltime.setText("time:  " + timeperturn);
			cline.setText("chat: ");
			return;
		}
		if (e.getActionCommand().compareTo("timer") == 0) {
			remainingtime--;
			if (remainingtime < 0) remainingtime=0;	//just in case
			ltime.setText("time:  " + remainingtime);
			System.out.printf("timer fired\n");
			return;
		}
	}

}
