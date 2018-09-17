 public class IntByte{
     public static void main(String args[]){
         byte b = (byte)0x00;
         int a[] = new int[1400];
         for (int i = 0; i<a.length;i++) a[i]=i;
         System.out.printf("b = %x = %d\n", b,b);
         int i = b;
         System.out.printf("i = %x = %d\n", b,b);
         i = i & 0xff;
         System.out.printf("i = %x = %d\n", b,b);
         for (i = 0; i<a.length; i++){
             for (int j = 0; j<20; j++){
                 
             }
             int j = 0,leng = 20,height = 70;

            //System.out.printf("here! i = %d  %d  %d  dif = %d\n", i, i+3, (i+3)%leng, (i+3)%leng-(i)%leng );
            System.out.printf("here! i = %d  %d  %d\n", i, (i)%leng, i%(height) );
         }
         System.out.printf("i = %x = %d\n", b,b);
         
     }
 }