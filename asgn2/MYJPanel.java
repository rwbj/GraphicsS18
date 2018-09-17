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
    int x1,x2,y1,y2,x3,y3;
    MyPoint p1,p2,p3;
    
	

	public MYJPanel() {

		super();
	}

	public void setLnPts(int n1, int n2, int n3, int n4, int n5, int n6){
		x1 = n1;
		y1 = n2;
		x2 = n3;
        y2 = n4;
        x3 = n5;
        y3 = n6;
    }
    
    public void setPts(MyPoint initalP1, MyPoint initalP2, MyPoint initalP3){
        p1 = initalP1;
        p2 = initalP2;
        p3 = initalP3;
        
        x1 = p1.x;
        y1 = p1.y;
        x2 = p2.x;
        y2 = p2.y;
        x3 = p3.x;
        y3 = p3.y;

        System.out.printf("pts=\n%s\n%s\n%s\n%d\n",p1.toString(),p2.toString(),p3.toString(),p1.x);

    }

    public void transform(String []command){

        switch(command[0].charAt(0)){
            case 'R':
                p1.rotate(Double.parseDouble(command[1]));
                p2.rotate(Double.parseDouble(command[1]));
                p3.rotate(Double.parseDouble(command[1]));
                break;
            case 'T':
                p1.translate(Integer.parseInt(command[1]),Integer.parseInt(command[2]));
                p2.translate(Integer.parseInt(command[1]),Integer.parseInt(command[2]));
                p3.translate(Integer.parseInt(command[1]),Integer.parseInt(command[2]));
                break;
            case 'S':
                p1.scale(Double.parseDouble(command[1]),Double.parseDouble(command[2]));
                p2.scale(Double.parseDouble(command[1]),Double.parseDouble(command[2]));
                p3.scale(Double.parseDouble(command[1]),Double.parseDouble(command[2]));
                break;
            default: System.out.printf("no operation found\n");
                break;
        }
    }

	public synchronized void paintComponent(Graphics g) {

		int i,j,w,h;

		g2d = (Graphics2D) g;


		w = 1040;
		h = 551;

		g2d.setColor(Color.BLACK);

		//g2d = img.createGraphics();
		
		//g2d.drawImage(img, null, 0, 0);
        
        //g2d.drawLine(x1,y1,x2,y2);

        g2d.clearRect(0,0,w,h);

        g2d.drawLine((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y);
        g2d.drawLine((int)p1.x, (int)p1.y, (int)p3.x, (int)p3.y);
        g2d.drawLine((int)p3.x, (int)p3.y, (int)p2.x, (int)p2.y);
        
        
		//saves the buffered image to file (Bobby's code)
		/*try {
            File outputfile = new File("saved.png");
            ImageIO.write(img, "png", outputfile);
        } catch (IOException e) {
          System.out.println("Something went wrong with saving the file");
        }*/

    }
}