public class imgProc{

    public static void main(String []args){
        if (args.length == 2) new Carver(args[0],args[1]);
        else{System.out.println("ERROR: please enter \"imageName.jpg\" \"filterName\" as arguments");}
    }
}
