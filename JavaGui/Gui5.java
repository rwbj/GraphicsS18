import javax.swing.*;
import java.awt.*;
import java.awt.event.*;



public class Gui5 extends JFrame implements ActionListener{

	static JFrame bframe;
	static JPanel p;
	static JLabel f1;
	static JLabel target;
	static Timer tm;



	public Gui5(int h, int w) {
		JButton btn;
		p = new JPanel(new GridLayout(w,h-1));  
		this.add(p);
		for (int i=0; i< w*h; i++)  {
			btn = new JButton();
			btn.addActionListener(this);
			btn.setActionCommand("btn: " +  i);
			p.add(btn);
		}
		tm = new Timer(1000, this);
		tm.setActionCommand("timer");
		tm.start();
	}







	public void actionPerformed(ActionEvent e) {


		if (e.getActionCommand().compareTo("timer") == 0) {
			System.out.printf("timer fired\n");
			return;
		}

		//GETS me the object which experienced the event
		JButton jb = (JButton) e.getSource();

		//GETS the string back which I set above (in case the object is not enough)
		System.out.printf("%s\n", e.getActionCommand());

		//PUT an image on a button, and understand String comparison
		jb.setIcon(("btn: 3".compareTo(e.getActionCommand()) == 0) ? new ImageIcon("cute.png") : new ImageIcon("cute2.png"));


ImageIcon ii = new ImageIcon("cute.png");
System.out.printf("widthy = %d   height= %d\n", ii.getIconWidth(), ii.getIconHeight());

	}

}
