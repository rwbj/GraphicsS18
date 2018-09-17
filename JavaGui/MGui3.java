import javax.swing.*;
import java.awt.*;
import java.awt.event.*;



class MGui3 {

	public static void main(String[] args) {


		JFrame bframe=new Gui3();


                bframe.setSize(400,400);
/*
                bframe.setSize(java.awt.GraphicsEnvironment.getLocalGraphicsEnvironment().getMaximumWindowBounds().width

			,java.awt.GraphicsEnvironment.getLocalGraphicsEnvironment().getMaximumWindowBounds().height);

*/

	

		bframe.setLocation(0,0);
		bframe.setVisible(true);
		bframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
