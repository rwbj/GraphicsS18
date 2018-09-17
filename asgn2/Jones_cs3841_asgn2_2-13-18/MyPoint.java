import java.awt.Point;

public class MyPoint extends Point{

    int x,y;

    public MyPoint(){
        super();
    }

    public MyPoint(int x, int y){
        super(x,y);
    }

    public void rotate(double d){
		double x1=(double)x*Math.cos(d)-(double)y*Math.sin(d);
        double y1=(double)x*Math.sin(d)-(double)y*Math.cos(d);
        x = (int)x1;
        y = (int)y1;
		System.out.printf("r %d,%d by %d = %d,%d\n",x,y,d,x1,y1);
	}

	public void scale(double sx, double sy){
		double x1 = x*sx;
		double y1 = y*sy;
        x = (int)x1;
        y = (int)y1;
		System.out.printf("s %d,%d by %dx & %dy = %d,%d\n",x,y,sx,sy,x1,y1);
	}

	public void translate(int dx, int dy){
		x = x+dx;
		y = y+dy;
		System.out.printf("t %d,%d by %dx & %dy = %d,%d\n",x,y,dx,dy,x,y);
	}

}