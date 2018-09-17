import java.util.Arrays;

class Split{
    public static void main(String[] args){
        //String s = Arrays.deepToString(args);
        String[] s = args[0].split(",");
        for (String sa:s)
            System.out.printf("array: %s\n",sa);

    }
}