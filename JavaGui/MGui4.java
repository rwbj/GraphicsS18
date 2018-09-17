import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class MGui4 {

	public static void main(String[] args) {


		JFrame bframe=new Gui4();	//CREATE me and

                bframe.setSize(480,160);

		bframe.setLocation(0,0);				//where my upper left hand corner goes
		bframe.setVisible(true);				//I start out invisible
		bframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	//need this for the window manager
	}
}
