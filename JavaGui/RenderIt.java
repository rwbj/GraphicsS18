import java.awt.image.DataBufferByte;
import java.io.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.GridBagLayout;
import java.awt.image.*;
import javax.imageio.*;
import java.awt.image.*;
import java.util.*;



public class RenderIt  extends JFrame {
	static JFrame bframe;
	static MYJPanel p;
	int[] face0=new int[15];
	int[] face1=new int[15];
	int[] face2=new int[15];
	int[] face3=new int[15];

	public RenderIt() {

		//FRONT FACE
		face0[0] = 210;  face0[1] = 210;   face0[2] = 0;
		face0[3] = 410;  face0[4] = 210;   face0[5] = 0;
		face0[6] = 410;  face0[7] = 410;   face0[8] = 0;
		face0[9] = 210;  face0[10]= 410;   face0[11]= 0;
		face0[12]= 210;  face0[13]= 210;   face0[14]= 0;


		//BACK FACE
		face1[0] = 210;  face1[1] = 210;   face1[2] = 100;
		face1[3] = 410;  face1[4] = 210;   face1[5] = 100;
		face1[6] = 410;  face1[7] = 410;   face1[8] = 100;
		face1[9] = 210;  face1[10]= 410;   face1[11]= 100;
		face1[12]= 210;  face1[13]= 210;   face1[14]= 100;


		//RIGHT
		face2[0] = 410;  face2[1] = 210;   face2[2] = 0;
		face2[3] = 410;  face2[4] = 210;   face2[5] = 100;
		face2[6] = 410;  face2[7] = 410;   face2[8] = 100;
		face2[9] = 410;  face2[10]= 410;   face2[11]= 0;
		face2[12]= 410;  face2[13]= 210;   face2[14]= 0;


		//LEFT
		face3[0] = 210;  face3[1] = 210;   face3[2] = 0;
		face3[3] = 210;  face3[4] = 210;   face3[5] = 100;
		face3[6] = 210;  face3[7] = 410;   face3[8] = 100;
		face3[9] = 210;  face3[10]= 410;   face3[11]= 0;
		face3[12]= 210;  face3[13]= 210;   face3[14]= 0;


		p = new MYJPanel(face0,face1,face2,face3,310,310,200);
	}



	public static void main (String[] args) {

	    try {

		bframe=new RenderIt();
		bframe.add(p);
		bframe.setSize(512,512);
		bframe.setLocation(0,0);
		bframe.setVisible(true);

		bframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	    } catch (Exception e) {
		System.out.println(e.getMessage());
	    }
	}
}








