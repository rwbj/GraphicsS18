import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class MGui2 {

	public static void main(String[] args) {


		JFrame bframe=new Gui2();


                bframe.setSize(java.awt.GraphicsEnvironment.getLocalGraphicsEnvironment().getMaximumWindowBounds().width,
					java.awt.GraphicsEnvironment.getLocalGraphicsEnvironment().getMaximumWindowBounds().height);


	

		bframe.setLocation(0,0);				//where my upper left hand corner goes
		bframe.setVisible(true);				//I start out invisible
		bframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	//need this for the window manager
	}
}
