import javax.swing.*;
import java.awt.*;
import java.awt.event.*;



class MGuix {

	public static void main(String[] args) {


		JFrame bframe=new Guix();


                bframe.setSize(800,400);

		bframe.setLocation(100,100);
		bframe.setVisible(true);
		bframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
