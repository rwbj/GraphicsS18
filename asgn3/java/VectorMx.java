import java.util.Arrays;

public class VectorMx{
    float []v = {0,0,0,1};

    public VectorMx(float x,float y,float z){
        setV(x,y,z);
    }

    public float[] getV(){
        return v;
    }

    public void setV(float x,float y,float z){
        v[0] = x;
        v[1] = y;
        v[2] = z;
    }
    
    public void trans(float[][] mx){
        float [][]temp = new float[4][4];
        for (int i = 0;i<4;i++){
            for (int j = 0; j<4;j++){
                temp[i][j] = mx[i][j]*v[j];
            }
        }
        for (int i = 0;i<4;i++){
            v[i] = temp[i][0]+temp[i][1]+temp[i][2]+temp[i][3];
        }
    }

    public String toString(){
        return Arrays.toString(v);
    }
}