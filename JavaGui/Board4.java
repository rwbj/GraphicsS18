/*

client for a distributed, multi-user, form-a-word game

a bit of a hacked up mixture-
basically, Board4.java is swing components, and
MYJPanel is manual 2d graphics 

the do-it-youself button approach does have some positives, exepcially when it comes
to platform independence... it won't scale easily or far, but then again it 
probably won't ever need to.

we'll jump one way or the other if this ever goes anywhere


This is under development, so you should not have a copy and/or be reading this.
If for some reason you are, you may not copy, use, transmit, do anything at all with any of this code, in 
part or in whole.

Appropriate licensing will be instated after the code is released.


copyright 2015, LucidityVR Inc,
all rights reserved

*/



import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import java.util.Arrays;
import java.util.Random;

public class Board4 extends JFrame implements ActionListener, MouseListener, KeyListener{
	private static final long serialVersionUID = 271828l;
	//public static final int TURNSPERGAME=2;
	Player3 soundEffect=null;
	MYJPanel p;
	Timer tm;
	int which, turn=0, pcnt=0;
	static final int MAXPLAYERS=4;
	String name;
	//volatile String agmsg;
	JTextField chat=null;
	JLabel chatw=null;
	DataOutputStream serverbw=null;
	String chatText=null;
	boolean audioState=true;
	HighScore rPanel=null;

	//game settings, will come froma GUI/user driven 'settings' screen later
	void setGameSettings (byte[] b) {
		b[6] = 90; /* probability of regular board square */
		b[7] = 12; /* prob of quad word board square */
		b[8] = 12; /* prob of quad letter board square */
		b[9] = 18; /*  triple word */
		b[10] = 34; /* triple letter */
		b[11] = 22; /* double word */
		b[12] = 37; /* double letter */
		b[13] = Sme.turnCount; /* turns/game */
		b[14] = 60; /* seconds/turn */


		b[6]=10;
		b[7]=52;
		b[8]=52;
	}


	public void mousePressed(MouseEvent e) {
		int dx,dy,x,y;
		double dst;
		x = e.getX();  y = e.getY();

                //start button
                dx = (((x-100)*(x-100)) + ((y-57) * (y-57)));
                dst = dx;
                dst = Math.sqrt(dst);
                if (dst < 45.0)  {
			try {
				System.out.println("start the game");
				setGameSettings(Sme.startMessage);
				serverbw.write(Sme.startMessage);
				serverbw.flush();
			} catch (Exception ex) {
				ex.printStackTrace();
				System.exit(1);
			}
		}
	}




	public void mouseReleased(MouseEvent e) {
		if (e.getSource() instanceof JButton) {

			/* convert  coordinate system: jbutton -> window coords */
			MouseEvent me = new MouseEvent((JButton) e.getSource(), 
			MouseEvent.MOUSE_RELEASED, e.getWhen(), e.getModifiers(), e.getX() + 30,
			e.getY() + 232, e.getXOnScreen(), e.getYOnScreen(), 1, false, MouseEvent.BUTTON1);

			p.mouseReleased(me);
		}
	}


	public void mouseEntered(MouseEvent e) {
	}

	public void mouseExited(MouseEvent e) {
	}

	public void mouseClicked(MouseEvent e) {
	}




	void countDown() {
		String ct=null;

		try {
			ct = chatw.getText();
			chatw.setText(null);
			chatw.setIcon(null);

			chatw.setIcon(new ImageIcon("images/spacer.png"));
chatw.setText("<html><center><font face=\"Arial Rounded MT Bold\" size=7><font color=\"red\"><b>Turn " + turn + "</font></center></html>");
			long sleepTime = (turn==1) ? 1600 : 6000;
sleepTime = 6000;
			Thread.sleep(sleepTime);
			chatw.setText(null);

			soundEffect.playIt("audio/countDown.wav");
			if (audioState) soundEffect.t.interrupt();

			chatw.setIcon(new ImageIcon("images/br3.png"));
			p.repaint();
			Thread.sleep(1200);

			chatw.setIcon(new ImageIcon("images/br2.png"));
			p.repaint();
			Thread.sleep(1200);

			chatw.setIcon(new ImageIcon("images/br1.png"));
			p.repaint();
			Thread.sleep(1200);

			if (rPanel != null)
 				rPanel.dispatchEvent(new WindowEvent(rPanel, WindowEvent.WINDOW_CLOSING));
			chatw.setIcon(new ImageIcon("images/brgo.png"));
			p.repaint();
			Thread.sleep(1200);

			chatw.setIcon(null);
			chatw.setText(ct);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}




	//implements protocol with the server after initial handshake
	void processMessage(String m) {
System.out.println(">>>>>>>>>>>>>got " + m + "  len = " + m.length());

		if (m.startsWith("error=")) {
			if (turn == 3) 
JOptionPane.showMessageDialog(null, "communication with server failed - sorry", "fatal error :(", JOptionPane.ERROR_MESSAGE);
			else
JOptionPane.showMessageDialog(null, "www.AmysGame.com  please send bugs/requests to: rjoyce@zoho.com", "Thank you for playing Amy's game :)", JOptionPane.PLAIN_MESSAGE);
			System.exit(2);
		}

		//if (m.compareTo("state=NOTREADY") == 0)  p.showme = p.waitf;
		if (m.compareTo("state=NOTREADY") == 0)  chatw.setText("<html><font face=\"Arial Rounded MT Bold\" size=5 color=\"red\"><center>Waiting for the server</center></font></html>");


		if (m.compareTo("state=slow") == 0)  {	
			JOptionPane.showMessageDialog(null, "Your network connection is too slow - sorry", "fatal error :(", JOptionPane.ERROR_MESSAGE);
			System.exit(3);
		}

		if (m.compareTo("state=evil") == 0)  {	
			JOptionPane.showMessageDialog(null, "Hmmm, from whence came that word?", "fatal error :(", JOptionPane.ERROR_MESSAGE);
			System.exit(4);
		}


		if (m.startsWith("plist=")) {
			int bi,ei;
			bi=m.indexOf('='); ei=m.indexOf(',');
			bi++;
			p.showme=null;
			String starter = m.substring(bi,ei);
			String playerList = m.substring(bi);
			String[] plist = playerList.split(",");
			p.names=plist;
			pcnt = plist.length;

			if (name.compareTo(starter) == 0) {
				chatw.setText(null);
				chatw.setIcon(new ImageIcon("images/startb2.png"));
				p.repaint();
			} else {
chatw.setText("<html><center><font face=\"Arial Rounded MT Bold\" size=5>Waiting for<br><font color=\"red\"><b>" + starter + "</b></font><br> to start the game</center></font></html>");
				p.repaint();
			}
			return;
		}


		if (m.startsWith("ack=")) {
			if (p != null)
				p.lastPlay.acknak=true;
		}



/*
turnResults=2,cal =50,50,joy,0,calvin =48,48,jeez,2,
*/

		if (m.startsWith("turnResults=")) {
System.out.println(".............................turnResults for " + turn);
                        int myi=0,ub;

                        //pick the message apart
                        String[] slist = m.split(",");
                        int playercnt = (slist.length-1)/5;
                        TurnMetric[] pidata = new TurnMetric[playercnt];

                        //get sorted list of results
                        for (int z=0; z<pidata.length; z++) {
                                pidata[z] = new TurnMetric();
                                pidata[z].name = slist[1+(z*5)];
                                pidata[z].last = Integer.parseInt(slist[2+(z*5)]);
                                pidata[z].total = Integer.parseInt(slist[3+(z*5)]);
                                pidata[z].ss = Integer.parseInt(slist[4+(z*5)]);
                                pidata[z].word = new String(slist[5+(z*5)]);
                        }

			p.setImage("images/ag15.png");
			try { Thread.sleep(1000); } catch (Exception tmpe) {}

                        Arrays.sort(pidata);
			p.scores = pidata;
			rPanel = new HighScore(pidata, p.tiles, p.orack, p.board, turn);
			rPanel.setVisible(true);
			rPanel.setSize(383, 624);
			Point mpt = this.getLocation();
			mpt.x += 256;  mpt.y += 64;
//left,right,up,down
			rPanel.setLocation(mpt.x,mpt.y);
			rPanel.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
			if(turn == Sme.turnCount) {
System.out.println("GAME OVER");
Timer tmo = new Timer(15000, this);
tmo.setActionCommand("alldone");
tmo.start();
this.setVisible(false);
				if (pidata[0].name.compareTo(name) == 0) {
System.out.println("YOU WON!!");
					soundEffect.playIt("audio/winner2.wav");
					try {
						soundEffect.t.interrupt();
                        //soundEffect.playIt("audio/countDown.wav");
                        //if (audioState) soundEffect.t.interrupt();

						soundEffect.t.join();
					} catch (Exception e) {
System.out.println("oh well, missed the show");
					}
				}
			}
		}






		if (chatw != null) {
		    Font tfont=null;
		    int bi,ei; boolean firstLine=true;
		    if (m.startsWith("chat=")) {

			tfont = p.g2d.getFont();
			p.g2d.setFont(p.f10p);
			bi=m.indexOf('='); ei=m.indexOf(':');
			String name = m.substring(bi+1,ei+1);
			String msg = m.substring(ei+1);

			String tm = "<b><font color=\"red\">"  + name + "<br></font></b>";
			bi=ei=0;
			for (int i=0; i<msg.length(); i++) {
				ei++;
				if (p.g2d.getFontMetrics().stringWidth(msg.substring(bi,ei)) > (chatw.getWidth()-20)) {
					if (bi >= ei) return;	//can't happen in theory, unless a very wierd default font is in use
					tm += msg.substring(bi,ei-1) + "<br>";
					bi=ei=i;
					if (firstLine)
						firstLine=false;
					else 
						bi--;
				}
			}
			tm += msg.substring(bi) + "<br>";


			if (chatText == null)
				chatText = tm;
			else
				chatText += tm;

			chatw.setText("<html>" + chatText + "</html>");
			if (tfont != null) p.g2d.setFont(tfont);
		    }
		}






		if (m.startsWith("turn=")) {
			int ti = m.indexOf('=');
			int tb = m.indexOf(',');
			String tnum = m.substring(ti+1,tb);
			turn = Integer.parseInt(tnum);


			ti = m.indexOf("board=");
			String s2=m.substring(ti+6);
			String tbrd = s2.substring(0,p.board.length);




			for (int z=0; z<tbrd.length(); z++)
System.out.printf("board[%d] = %c \n", z, tbrd.charAt(z));
System.out.println(" - ");


			ti = m.indexOf("rack=");
			String trck = m.substring(ti+5);

System.out.println("turn: " + turn);
System.out.println(" board: " + tbrd);
System.out.println(" rack: " + trck);

			setTitle("Amy's Game             Turn " + turn);
			if (turn==1) {
				chatw.setText(" ");
				chatw.setIcon(null);
			} 
			p.turnNumber = (byte) turn;
			countDown();

			try {
				p.orack = trck.getBytes("US-ASCII");
				p.rack = trck.getBytes("US-ASCII");
				p.board = tbrd.getBytes("US-ASCII");
				p.played = new byte[7];
				p.blankSpot = -1;
				p.turnNumber = (byte) turn;
				p.wscore=null;
				p.lastPlay=null;
				p.resetSecondsRemaining();
				tm.start();
				for (int l=0; l<p.played.length; l++) p.played[l]=0;
				p.resetImage(false);
			} catch (Exception e3) {
				e3.printStackTrace();
				System.exit(7);
			}
		}
	}


	public void keyTyped(KeyEvent e) {
		int mlen, nfc;
		JTextField f;
		f = (JTextField) e.getSource();

		if (e.getKeyChar() == '\n') {
System.out.println("send: " + f.getText());
System.out.println("send length = " + f.getText().length());
			if (f==null) return;
			String sts = f.getText();
			if (sts == null) return;
			if (sts.length() == 0) return;
			if (turn <= 0) return;

			nfc=5;
			try {
				Sme.init();
				byte[] mnb = name.getBytes("US-ASCII");
				for (int i=0; i<mnb.length; i++)
					Sme.chatMessage[nfc++] = mnb[i];
				Sme.chatMessage[nfc++] = ':';
				Sme.chatMessage[nfc++] = ' ';

				byte[] msg = f.getText().getBytes("US-ASCII");
				for (int i=0; i<msg.length; i++) {
					Sme.chatMessage[nfc++] = msg[i];
					if (nfc == Sme.chatMessage.length) break;
				}
				try {
					serverbw.write(Sme.chatMessage);
				} catch (Exception ex) {
					ex.printStackTrace();
				}
			} catch (UnsupportedEncodingException uee) {
				uee.printStackTrace();
			} finally {
				Sme.init();
				f.setText(null);
			}

		}
	}

	public void keyPressed(KeyEvent e) {
	}

	public void keyReleased(KeyEvent e) {
	}




	public Board4() {
		int i;
		Color bc, bkc;
		BufferedReader br;

		soundEffect = new Player3("audio/tick.wav");
		bc = new Color(239,228,176);
		bkc = new Color(49,49,49);
		audioState=true;



		p = new MYJPanel();
		this.add(p);


		p.setLayout(null);
		chat = new JTextField(16);
		p.add(chat);
		chat.setBounds(59,447,200,20);
		chat.setBackground(p.wcolor);
		chat.setActionCommand("chat");
		chat.setFont(p.f14p);
		chat.addKeyListener(this);

	chatw = new JLabel(" ");
	JScrollPane scroll = new JScrollPane(chatw);
	p.add(scroll);
	scroll.setBounds(60,310,200,122);
	chatw.setBounds(60,310,200,122);
	chatw.setFont(p.f10p);
	chatw.setForeground(p.bcolor);
	chatw.addMouseListener(this);

		JButton shuffle = new JButton(new ImageIcon("images/shuffle.png"));
		shuffle.setBounds(253,265,33,34);
		shuffle.addActionListener(this);
		shuffle.setActionCommand("shuffle");
		shuffle.setBorder(null);
		p.add(shuffle);


		JButton recall = new JButton(new ImageIcon("images/recall.png"));
		recall.setBounds(30,265,33,34);
		recall.addActionListener(this);
		recall.setActionCommand("recall");
		recall.setBorder(null);
		p.add(recall);

		JButton send = new JButton(new ImageIcon("images/sendc.png"));
		send.setBounds(30,232,32,34);
		send.addActionListener(this);
		send.setActionCommand("send");
		send.setBorder(null);
		send.addMouseListener(this);
		p.add(send);

		JButton audio = new JButton(new ImageIcon("images/audioOna.png"));
		audio.setBounds(254,232,32,34);
		audio.addActionListener(this);
		audio.setActionCommand("audio");
		audio.setBorder(null);
		p.add(audio);





		setTitle("Amy's Game");

		tm = new Timer(1000, this);
		tm.setActionCommand("timer");
		this.repaint();
		p.repaint();
	}










	public void actionPerformed(ActionEvent e) {

		if (e.getActionCommand().compareTo("shuffle") == 0) {
			p.shuffle();
			p.repaint();
System.out.println("shuffle");
		}
		if (e.getActionCommand().compareTo("recall") == 0) {
			p.recall();
			p.repaint();
System.out.println("recall");
		}
		if (e.getActionCommand().compareTo("send") == 0) {
System.out.println("send");
		}

		if (e.getActionCommand().compareTo("audio") == 0) {
			JButton te = (JButton) e.getSource();
			if (audioState) {
				audioState=false;
				te.setIcon(new ImageIcon("images/audioOffa.png"));
			} else {
				audioState=true;
				te.setIcon(new ImageIcon("images/audioOna.png"));
			}
System.out.println("send");
		}




		if (e.getActionCommand().compareTo("alldone") == 0) {
			System.exit(0);
		}

		if (e.getActionCommand().compareTo("timer") == 0) {
			if (p.secondsRemaining > 0) {
				p.tick();
				switch (p.secondsRemaining) {
					case 0:
						soundEffect.playIt("audio/eot22.wav");
						p.setImage("images/ag15.png");
try { Thread.sleep(300); } catch (Exception eee) {}
p.repaint();
						//if (turn == Sme.turnCount) setVisible(false);
						p.repaint();
						break;
					case 1:
						soundEffect.playIt("audio/eot11.wav");
						break;

					case 2:
						soundEffect.playIt("audio/eot00.wav");
						break;

					case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
						soundEffect.playIt("audio/tickLouder.wav");
						break;
					default:
						soundEffect.playIt("audio/tick.wav");
						break;
				}
				if (audioState) soundEffect.t.interrupt();
			}
			p.repaint();
		}
	}

}
