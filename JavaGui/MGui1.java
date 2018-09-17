import javax.swing.*;
import java.awt.*;
import java.awt.event.*;



public class MGui1 {

	static JFrame bframe;

	public static void main(String[] args) {


		bframe=new Gui1();

		//MY width,height in pixels
		bframe.setSize(200,500);


		//where my upper left hand corner goes
		bframe.setLocation(40,40);


		//I start out invisible
		bframe.setVisible(true);


		//need this for the window manager
		bframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}
