public class Matrix3D{
    float [][]mx = new float[4][4];
    
    public Matrix3D(){
        for (int i = 0; i<mx.length; i++){
            for (int j = 0; j<mx[i].length;j++){
                mx[i][j] = 0;
            }
        }
    }

    public Matrix3D(float []vec1, float[]vec2, float []vec3, float []vec4){
        setMx(vec1, vec2, vec3, vec4);
    }

    public float[][] getMx(){
        return mx;
    }

    public void setMx(float []vec1, float[]vec2, float []vec3, float []vec4){
        mx[0] = vec1;
        mx[1] = vec2;
        mx[2] = vec3;
        mx[3] = vec4;
    }

}