
interface ADDx{
    public int addNum(int a,int b,int c);
}

public class LamdaExp2 {
    public static void main(String[] args) {
        ADDx adx = (int x, int y, int z)->{
            System.out.println("Addingng");
            return x+y+z;
        };
        System.out.println(adx.addNum(10, 20, 30));
    }
    
}
