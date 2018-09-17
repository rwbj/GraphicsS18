import javax.swing.*;
import java.awt.*;
import java.awt.event.*;



public class Gui2 extends JFrame implements ActionListener{

	static JFrame bframe;
	static JPanel p;
	static JLabel f1,f2;	//one says 'hello', the screams yellow


	public Gui2() {
		p = new JPanel();
		this.add(p);

		f1 = new JLabel("hello there, how is this working out for you so far?");
		p.add(f1);		//add it to the JPanel


		f2 = new JLabel("YELLOW!");
		f2.setForeground(Color.yellow);
		f2.setFont(new Font("Arial Rounded MT Bold", Font.PLAIN, 72));
		p.add(f2);
	}





	public void actionPerformed(ActionEvent e) {
	}

}
