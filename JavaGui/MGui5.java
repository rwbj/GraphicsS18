import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


class MGui5 {

	public static void main(String[] args) {

		int width, height;
		double prob;



		width = Integer.parseInt(args[0]);
		height = Integer.parseInt(args[1]);
		prob = Double.parseDouble(args[2]);

		JFrame bframe=new Gui5(width, height);	//CREATE me and


		bframe.setLocation(32,32);
        bframe.setSize(64*width, 64*height);
		bframe.setVisible(true);
		bframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
