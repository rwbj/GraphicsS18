import javax.swing.*;
import java.awt.*;
import java.awt.event.*;



public class Gui6 extends JFrame implements ActionListener{

	JFrame bframe;
	JPanel p,p2;
	Timer tm;
	int count=0;
	JButton jb;
	JLabel[] lbl;



	public Gui6(int h, int w) {
		lbl = new JLabel[h*w];

		//TOP PANEL OF the gui uses a border layout
		p = new JPanel(new BorderLayout());

		//CENTER COMPONENT of the border layout is another JPanel which ues a GridLayout
		p2 = new JPanel(new GridLayout(w,h-1));  
		this.add(p);

		p.add(p2, BorderLayout.CENTER);

		//THE BUTTON at the bottom
		jb = new JButton("start");
		jb.setActionCommand("start");
		jb.addActionListener(this);
		p.add(jb, BorderLayout.SOUTH);
		jb.setSize(32,200);

		//THE LABELS IN the grid
		for (int i=0; i< w*h; i++)  {
			lbl[i] = new JLabel("tick");
			p2.add(lbl[i]);
		}
	}







	public void actionPerformed(ActionEvent e) {


		//HERE BECAUSE THE TIMER FIRed
		if (e.getActionCommand().compareTo("timer") == 0) {
			lbl[count++].setText("tock");
			System.out.printf("timer fired\n");
			return;
		}

		//GETS me the object which experienced the event
		JButton jb = (JButton) e.getSource();

		//GETS the string back which I set above (in case the object is not enough)
		System.out.printf("%s\n", e.getActionCommand());

		//HERE BECAUSE THE  Button was clicked
		if (e.getActionCommand().compareTo("start") == 0) {
			tm = new Timer(1000, this);
			tm.setActionCommand("timer");
			tm.start();
		}
	}

}
