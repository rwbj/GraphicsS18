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
    int x1,y1,x2,y2,x3,y3;
    Scanner inStream;
    List<String[]> actions = new ArrayList<>(0);

	public Gui(String dataFile){//String img, int n1, int n2, int n3, int n4) {
		
		/*x1 = n1;
		y1 = n2;
		x2 = n3;
        y2 = n4;*/
        
        this.getData(dataFile);

        p2 = new MYJPanel();
        //p2.setLnPts(100,100,300,100,300,300);

        x1 = Integer.parseInt(actions.get(0)[0]);
        y1 = Integer.parseInt(actions.get(0)[1]);
        x2 = Integer.parseInt(actions.get(0)[2]);
        y2 = Integer.parseInt(actions.get(0)[3]);
        x3 = Integer.parseInt(actions.get(0)[4]);
        y3 = Integer.parseInt(actions.get(0)[5]);

        //p2.setPts(new MyPoint(100,100),new MyPoint(300,100),new MyPoint(300,300));
        p2.setPts(new MyPoint(x1,y1),new MyPoint(x2,y2),new MyPoint(x3,y3));

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
    }

	public void actionPerformed(ActionEvent e){
		if (e.getActionCommand().compareTo("tm")==0){
            if(count>(actions.size()-2)){
                count = 0;
            }
            p2.transform(actions.get(count+1));
			p2.repaint();
            if (count%2==0){
                System.out.println("tick");
            }else{
                System.out.println("tock");
            }
            count++;
		}
	}

}