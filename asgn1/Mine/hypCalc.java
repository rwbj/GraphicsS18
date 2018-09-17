import java.lang.Integer;

public class hypCalc{
    public static void main(String[] args){
        int x1, y1, x2, y2, x, y, xMax;
        double m;
        x1 = Integer.parseInt(args[0]);
        y1 = Integer.parseInt(args[1]);
        x2 = Integer.parseInt(args[2]);
        y2 = Integer.parseInt(args[3]);
        System.out.printf("%n"+x1+","+y1+" "+x2+","+y2);
        //y1-y2 = m(x1-x2)
        //y = m(x-x1)+y1
        m = (double)(y1-y2)/(double)(x1-x2);
        System.out.printf("%nm = " + m);

        if(x1<x2){
            x = x1;
            xMax = x2;
        }
        else{
            x = x2;
            xMax = x1;
        }

        for(; x<xMax; x++){
            y = (int)(m*(x-x1)) + y1;
            System.out.printf("%n%d,%d",x,y);
        }
    }
}