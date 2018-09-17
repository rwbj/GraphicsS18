import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.imageio.ImageIO;
import java.io.File;
import java.awt.image.BufferedImage;
import java.awt.image.DataBufferByte;
import java.lang.Math;


public class Carver extends JFrame implements ActionListener{
        JButton jb;
        JFrame bframe;
        JPanel jp;
        JLabel f1,f2,f3,f4;     //one says 'hello', the screams yellow
        byte[] pixels2=null;
        String fname=null, fs;
        int cnt=0; int w,h,l,p;

        static int identity[][] = {{0,0,0},{0,1,0},{0,0,0}};

        static int box[][] = {{1,1,1},{1,1,1},{1,1,1}};

        static int bigbox[][] = {{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}};

        static int giantbox[][] = {{1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1}};

        static int sobel[][] = {{1,1,1},{0,0,0},{-1,-1,-1}};

        static int sharpen[][] = {{0,-1,0},{-1,5,-1},{0,-1,0}};

        static int gaussian[][] =   {{1,4,6,4,1},
                {4,16,24,16,4},
                {6,24,36,24,6},
                {4,16,24,16,4},
                {1,4,6,4,1}};

        static int unsharp[][] =  {{1,4,6,4,1},
                {4,16,24,16,4},
                {6,24,-476,24,6},
                {4,16,24,16,4},
                {1,4,6,4,1}};


        public Carver(String fn, String filterStr) {
                fs = filterStr;
                fname = new String(fn);
                jp = new JPanel();
                this.add(jp);


                jb = new JButton("carve");
                jb.addActionListener(this);
                jp.add(jb);


                BufferedImage i1=null;

                try {
                        i1 = ImageIO.read(new File(fname));
                        f3 = new JLabel(new ImageIcon(i1));
                        jp.add(f3);
                } catch (Exception e) {
                        System.out.println(fname + " read failed");
                        e.printStackTrace();
                }

                pixels2 = ((DataBufferByte) i1.getRaster().getDataBuffer()).getData();
                w=i1.getWidth();
                h=i1.getHeight();
                l=pixels2.length;
                p = l/(w*h);

                setSize(w,h);
                setLocation(100,100);
                setVisible(true);
                setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        }

        public void filter(int mask[][], int maskScale){
                byte nImg[] = new byte[l];
                for (int startIndex = 0; startIndex<l; startIndex+=3){
                        int index = startIndex;
                        double sum[] = {0x00,0x00,0x00};
                        double sum2[] = {0x00,0x00,0x00};
                        if ((startIndex + mask.length)%(w*p) < index%(w*p)) nImg[index] = nImg[index+1] = nImg[index+2] = 0x00;
                        else if (startIndex + (p*mask.length) + (p*mask[0].length*w) > l) nImg[index] = nImg[index+1] = nImg[index+2] = 0x00;
                        else{
                                for (int i = 0; i < mask.length; i++){
                                        for (int j = 0; j<mask[i].length; j++){
                                                index = startIndex + (p*i) + (p*j*w);
                                                if (index+2 < l){
                                                        for (int c = 0; c<3; c++){
                                                                sum[c] += ((int)pixels2[index + c] * ((double)mask[i][j] / maskScale));
                                                                sum2[c] += ((int)pixels2[index + c] * ((double)mask[j][i] / maskScale));
                                                        }
                                                }
                                                else{System.out.println("over: " + startIndex + " " + index);}
                                        }
                                }
                                for (int i =0; i<3; i++){
                                        if (mask == sobel) nImg[startIndex+i] = (byte)((int)Math.sqrt( (int)Math.pow(sum[i],2) + (int)Math.pow(sum2[i],2)));
                                        else nImg[startIndex+i] = (byte)((int)Math.sqrt( (int)Math.pow((byte)sum[i] & 0x000000ff,2) + (int)Math.pow(sum2[i],2)));
                                        
                                }
                        }
                }
                for (int i = 0; i<l ;i++) pixels2[i] = nImg[i];
        }

        public void actionPerformed(ActionEvent e) {
                int i;
                int r,g,b;
                cnt++;

                switch (fs){
                        case ("sobel"):
                                for (i=0; i<l; i+=p){
                                        r = (int)(pixels2[i+2] * 0.289);
                                        g = (int)(pixels2[i+1] * 0.587);
                                        b = (int)(pixels2[i] * 0.144);
                                        pixels2[i] = (byte)(r + g + b);
                                        pixels2[i+1] = (byte)(r + g + b);
                                        pixels2[i+2] = (byte)(r + g + b);
                                }
                                filter(sobel, -1);
                                break;
                        case ("gray"):
                                for (i=0; i<l; i+=p){
                                        r = (int)(pixels2[i+2] * 0.289);
                                        g = (int)(pixels2[i+1] * 0.587);
                                        b = (int)(pixels2[i] * 0.144);
                                        pixels2[i] = (byte)(r + g + b);
                                        pixels2[i+1] = (byte)(r + g + b);
                                        pixels2[i+2] = (byte)(r + g + b);
                                }
                                break;
                        case ("sharpen"):
                                filter(sharpen, 1);
                                break;
                        case ("gaussian"):
                                filter(gaussian, 256);
                                break;
                        case ("unsharpen"):
                                filter(unsharp, -256);
                                break;
                        case ("box"):
                                filter(box,9);
                                break;
                        case ("bigbox"):
                                filter(bigbox,25);
                                break;
                        case ("giantbox"):
                                filter(giantbox,81);
                                break;
                        default:
                                System.out.println("filter not recongized");
                                break;
                }

                System.out.println("carve");
                /*System.out.println("image Width: " + w);
                System.out.println("image Height: " + h);
                System.out.println("byte array length: " + pixels2.length);
                System.out.println("length/(h*w): " + l/(h*w));*/

                this.repaint();
        }

}

