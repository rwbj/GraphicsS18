import javax.swing.*;
import javax.imageio.*;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.IOException;



public class Gui6 extends JFrame {

	JPanel p;
	int mx,my;
	MYJPanel p2, p3;
	Timer tm;
	int count=0;
	JButton jbn, jbw, jbs, jbe;
	JButton[] lbl;



	public Gui6() {


		p2 = new MYJPanel();

		try {
    			p2.img = ImageIO.read(new File("./a0.png"));
		} catch (IOException e) {
			System.out.printf("img open failed\n");
			e.printStackTrace();
			System.exit(1);
		}

		p2.setSize(p2.img.getWidth(), p2.img.getHeight());

		this.add(p2);
	}

}
