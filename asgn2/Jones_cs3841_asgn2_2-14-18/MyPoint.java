import java.awt.Point;

public class MyPoint extends Point{

    public int x,y;

    public MyPoint(){
        super();
    }

    public MyPoint(int inX, int inY){
        x = inX;
        y = inY;
    }

    public void rotate(double d){
		double x1=(double)x*Math.cos(d)-(double)y*Math.sin(d);
        double y1=(double)x*Math.sin(d)+(double)y*Math.cos(d);
        x = (int)x1;
        y = (int)y1;
	}

	public void scale(double sx, double sy){
		double x1 = (double)x*sx;
		double y1 = (double)y*sy;
        x = (int)x1;
        y = (int)y1;
	}

	public void translate(int dx, int dy){
		x = x+dx;
		y = y+dy;
	}

}