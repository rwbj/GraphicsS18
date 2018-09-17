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


public class MYJPanel extends JPanel {
	Graphics2D g2d;
	BufferedImage img=null;


	public MYJPanel() {

		super();
	}




	public synchronized void paintComponent(Graphics g) {

		int i,j,w,h;

		g2d = (Graphics2D) g;
		g2d.drawImage(img, null, 0, 0); 

		w = img.getWidth();
		h = img.getHeight();

		for (i=0; i<w; i++)
			for (j=0; j<h; j++)
				System.out.printf("pixel %d,%d = %x\n", i,j,img.getRGB(i,j));


	}
}




