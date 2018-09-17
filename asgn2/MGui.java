import javax.swing.*;
import java.awt.*;

class MGui{

    public static void main(String[] args){
        
        String s = args[0];
        JFrame bframe = new Gui(s);/*args[0],
                Integer.parseInt(args[1]), 
                Integer.parseInt(args[2]), 
                Integer.parseInt(args[3]), 
                Integer.parseInt(args[4]));//*/

        bframe.setLocation(32,32);
        bframe.setSize(1040,551);
		bframe.setVisible(true);
        bframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        
    }
}