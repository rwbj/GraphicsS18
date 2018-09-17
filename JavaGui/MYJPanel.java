import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Insets;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.awt.Font;
import java.util.*;
import javax.swing.JPanel;
import javax.swing.JFrame;
import javax.imageio.*;
import java.util.Random;
import java.io.*;



public class MYJPanel extends JPanel {
	Graphics2D g2d;

	BufferedImage bgs=null, bg=null, img=null;
	Color bgc;

	int xmid, ymid;	/* center */
	int vp; /* vanishing point */
	int[] face0;
	int[] face1;
	int[] face2;
	int[] face3;



	public MYJPanel(int[] f0, int[]f1, int[] f2, int[] f3, int xm, int ym, int v) {

		super();
		face0=f0; face1=f1; face2=f2; face3=f3; xmid=xm; ymid=ym; vp=v;
		bgc = new Color(0x33, 0x99, 0xdd);
	}




	public synchronized void paintComponent(Graphics g) {

		g2d = (Graphics2D) g;
		int x1,y1,z1,x2,y2,z2;

		g2d.setColor(new Color(0xff, 0x99, 0xdd));
		g2d.fillRect(10,10,200,100);
		g2d.setColor(bgc);

		for (int i=0; i<(face0.length-3); i+=3)  {
			x1 = face0[i]; y1 = face0[i+1]; z1 = face0[i+2];
			x1 = x1 - (int)((x1-xmid) * ((float)z1/(float)vp));
			y1 = y1 - (int)((y1-xmid) * ((float)z1/(float)vp));

			x2 = face0[i+3]; y2 = face0[i+4]; z2 = face0[i+5];
			x2 = x2 - (int)((x2-xmid) * ((float)z2/(float)vp));
			y2 = y2 - (int)((y2-xmid) * ((float)z2/(float)vp));

			g2d.drawLine(x1,y1,x2,y2);
		}

		for (int i=0; i<(face1.length-3); i+=3)  {
			x1 = face1[i]; y1 = face1[i+1]; z1 = face1[i+2];
			x1 = x1 - (int)((x1-xmid) * ((float)z1/(float)vp));
			y1 = y1 - (int)((y1-xmid) * ((float)z1/(float)vp));

			x2 = face1[i+3]; y2 = face1[i+4]; z2 = face1[i+5];
			x2 = x2 - (int)((x2-xmid) * ((float)z2/(float)vp));
			y2 = y2 - (int)((y2-xmid) * ((float)z2/(float)vp));

			g2d.drawLine(x1,y1,x2,y2);
		}


		for (int i=0; i<(face2.length-3); i+=3)  {
			x1 = face2[i]; y1 = face2[i+1]; z1 = face2[i+2];
			x1 = x1 - (int)((x1-xmid) * ((float)z1/(float)vp));
			y1 = y1 - (int)((y1-xmid) * ((float)z1/(float)vp));

			x2 = face2[i+3]; y2 = face2[i+4]; z2 = face2[i+5];
			x2 = x2 - (int)((x2-xmid) * ((float)z2/(float)vp));
			y2 = y2 - (int)((y2-xmid) * ((float)z2/(float)vp));

			g2d.drawLine(x1,y1,x2,y2);
		}


		for (int i=0; i<(face3.length-3); i+=3)  {
			x1 = face3[i]; y1 = face3[i+1]; z1 = face3[i+2];
			x1 = x1 - (int)((x1-xmid) * ((float)z1/(float)vp));
			y1 = y1 - (int)((y1-xmid) * ((float)z1/(float)vp));

			x2 = face3[i+3]; y2 = face3[i+4]; z2 = face3[i+5];
			x2 = x2 - (int)((x2-xmid) * ((float)z2/(float)vp));
			y2 = y2 - (int)((y2-xmid) * ((float)z2/(float)vp));

			g2d.drawLine(x1,y1,x2,y2);
		}


		g2d.drawString("Hi there", 40,50);
		g2d.setFont(new Font("Arial Rounded MT Bold", Font.BOLD, 32));
		g2d.drawString("cs2401", 40,70);

for (int i=0; i<400; i++)
g2d.drawLine(i, 200+(int)Math.round(2*Math.sin(i*1.0)), i+1, 200+(int)Math.round(2*Math.sin(i*1.0)));

	}

}

