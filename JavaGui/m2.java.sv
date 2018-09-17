import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Insets;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.util.*;
import javax.swing.JPanel;
import javax.swing.JFrame;
import javax.imageio.*;
import java.util.Random;
import java.io.*;



public class MYJPanel extends JPanel {
	Graphics2D g2d;

	public MYJPanel() {
		super();
			...
	}



	public synchronized void paintComponent(Graphics g) {

		g2d = (Graphics2D) g;


			... g2d.drawLine(x1,y1,x2,y2);  ... etc
	}

}
