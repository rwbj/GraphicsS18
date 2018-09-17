import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.imageio.ImageIO;
import java.io.File;
import java.awt.image.BufferedImage;
import java.awt.image.DataBufferByte;



public class Carver extends JFrame implements ActionListener{
        JButton jb;
        JFrame bframe;
        JPanel p;
        JLabel f1,f2,f3,f4;     //one says 'hello', the screams yellow
        byte[] pixels2=null;
        String fname=null;
        int cnt=0; int w,h,l;


        public Carver(String fn) {
                fname = new String(fn);
                p = new JPanel();
                this.add(p);


                jb = new JButton("carve");
                jb.addActionListener(this);
                p.add(jb);


                BufferedImage i1=null, i2=null;

                try {
                        i1 = ImageIO.read(new File(fname));
                        f3 = new JLabel(new ImageIcon(i1));
                        p.add(f3);
                } catch (Exception e) {
                        System.out.println(fname + " read failed");
                        e.printStackTrace();
                }




                pixels2 = ((DataBufferByte) i1.getRaster().getDataBuffer()).getData();
                w=i1.getWidth();
                h=i1.getHeight();
                l=pixels2.length;

                setSize(w,h);
                setLocation(100,100);
                setVisible(true);
                setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        }

        //called with JButton?
        public void actionPerformed(ActionEvent e) {
                int i;
                cnt++;

                System.out.println("carve");
                System.out.println("image Width: " + w);
                System.out.println("image Height: " + h);
                System.out.println("byte array length: " + pixels2.length);

for (i=3*256*8; i<3*256*16; i++) { //0-ing out a range
	System.out.printf("d[%d] = %x\n", i, pixels2[i]);
	pixels2[i] = (byte) 0x00;
}

                for (i=0; i<l; i+=3) {

                        if (((i/3)%w) == cnt+155) {
                                pixels2[i] = pixels2[i+1]=pixels2[i+2]=0;
                        }

                }

                this.repaint();
        }

}

