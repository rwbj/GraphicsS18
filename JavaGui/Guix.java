import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;
import java.io.*;

public class Guix extends JFrame implements ActionListener{

	static JFrame bframe;
	static JPanel p;
	File f;
	int i=0;

	public Guix() {
		p = new JPanel(new GridLayout(10,10));  
		p.setBackground(new Color(255,255,190));
		this.add(p);

		for (f = new File("."); i<f.list().length; p.add(new JButton(f.list()[i++])));

		setTitle("File Browser");
	}


	public void actionPerformed(ActionEvent e) {
	}
}

