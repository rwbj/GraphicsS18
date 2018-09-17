import java.awt.image.*;
import java.awt.Font;
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
import java.util.*;
import javax.swing.JPanel;
import javax.swing.JFrame;
import javax.imageio.*;
import java.util.Random;
import java.io.*;
import java.awt.geom.*;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseEvent;
import javax.imageio.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.IOException;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import javax.swing.*;
import java.awt.Color;
import java.lang.Math;

public class MYJPanel extends JPanel{

    Graphics2D g2d;
	BufferedImage img=null;
	int x1,x2,y1,y2;
	

	public MYJPanel() {

		super();
	}

	public void setLnPts(int n1, int n2, int n3, int n4){
		x1 = n1;
		y1 = n2;
		x2 = n3;
		y2 = n4;
	}

	public synchronized void paintComponent(Graphics g) {

		int i,j,w,h;

		g2d = (Graphics2D) g;


		w = 1040;
		h = 551;

		g2d.setColor(Color.BLACK);

		//g2d = img.createGraphics();
		
		g2d.drawImage(img, null, 0, 0);
		
		g2d.drawLine(x1, y1, x2, y2);

		//saves the buffered image to file (Bobby's code)
		/*try {
            File outputfile = new File("saved.png");
            ImageIO.write(img, "png", outputfile);
        } catch (IOException e) {
          System.out.println("Something went wrong with saving the file");
        }*/

    }
}