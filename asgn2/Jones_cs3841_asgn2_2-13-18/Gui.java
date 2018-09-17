import javax.swing.*;
import javax.imageio.*;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

class Gui extends JFrame implements ActionListener{

    JPanel p;
	int mx,my;
	MYJPanel p2, p3;
	Timer tm;
	int count=0;
	JButton jbn, jbw, jbs, jbe;
	JButton[] lbl;
    int x1,y1,x2,y2;

	public Gui(String dataFile){//String img, int n1, int n2, int n3, int n4) {
		
		/*x1 = n1;
		y1 = n2;
		x2 = n3;
        y2 = n4;*/
        
        this.getData(dataFile);

        p2 = new MYJPanel();
        p2.setLnPts(100,100,300,300);

        
        
        

		
		/*try {
			p2.img = ImageIO.read(new File("./"+img));
		} catch (IOException e) {
			System.out.printf("img open failed\n");
			e.printStackTrace();
			System.exit(1);
		}*/

        //p2.setSize(p2.img.getWidth(), p2.img.getHeight());

		p2.setSize(1040,551);
		this.add(p2);
		

		tm = new Timer(100,this);
		tm.setActionCommand("tm");
		tm.start();
    }
    
    Scanner inStream;
    List<String[]> actions = new ArrayList<>(0);

    private void getData(String fn){
        try{
            inStream = new Scanner(new File(fn));
        }catch(IOException e){
            System.out.printf("error getting data file: %s\n",e.getMessage());
            System.exit(1);
        }
        while(inStream.hasNextLine()){

            actions.add(inStream.nextLine().split(" "));

        }
/*
        for (int j=0;j<actions.size();j++){
            System.out.println(actions.get(j).deepToString());
            for (int i = 0; i<actions.get(j).length; i++){
                System.out.println(actions.get(j)[i].toString());
            }
        }*/
    }

    private MyPoint perform(int step){
		MyPoint pt = new MyPoint();
		return pt;
    }

	public void actionPerformed(ActionEvent e){
		if (e.getActionCommand().compareTo("tm")==0){
			//p2 = new MYJPanel();
			p2.repaint();
			p2.setLnPts(x1+count,y1-count,x2-count,y2+count);
			count++;
		}
	}

}