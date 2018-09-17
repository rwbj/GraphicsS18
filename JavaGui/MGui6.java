import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


class MGui6 {

	public static void main(String[] args) {

		int width, height;

		width = Integer.parseInt(args[0]);
		height = Integer.parseInt(args[1]);

		JFrame bframe=new Gui6(width, height);	//CREATE me and


		bframe.setLocation(32,32);
                bframe.setSize(64*width, 64*height);
		bframe.setVisible(true);
		bframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
