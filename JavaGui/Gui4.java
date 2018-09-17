import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;
import java.net.*;



public class Gui4 extends JFrame implements ActionListener{

	JFrame bframe;
	JPanel p;
	JLabel f1;
	JLabel target;
	JButton jgo;
	JTextField userInput;
	JSplitPane jp;



	public Gui4() {
		BufferedReader br;

		p = new JPanel(new GridLayout(4,1));  // THIS LAYOUT MANAGER WILL Try to arrange components into a 4x1 grid
		this.add(p);

		//component 1
		f1 = new JLabel("please enter something below, then click the button");
		//p.add(f1);		//add it to the JPanel


		//the place to type
		userInput = new JTextField(48);
		//p.add(userInput);
		jp = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, f1,userInput);
		p.add(jp);

		//the button to click
		jgo = new JButton("click me");
		jgo.addActionListener(this);		//PART 1 OF how-to-do-something-when-a-button-is-clicked
		p.add(jgo);

		//the place to write 'got it' message
		target = new JLabel();
		target.setForeground(Color.blue);
		p.add(target);
	}







	public void actionPerformed(ActionEvent e) {
		target.setText("got it: " + userInput.getText());
	}

}
