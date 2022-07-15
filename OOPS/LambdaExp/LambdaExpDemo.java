
interface AddIntf{
    int add(int x,int y);
}
interface subIntf{
    int sub(int x,int y);
}
enum myEnum{
    first,second,third;
}
public class LambdaExpDemo {
    public void showSub(subIntf s,int x, int y)
    {
        int m = s.sub(x, y);
        System.out.println("m: "+ m);
    }
    public static void main(String[] args) {

        myEnum me = myEnum.first;
        System.out.println(me);
        /*AddIntf addIntf = (int x,int y)->{return x+y;};
        System.out.println(addIntf.add(100,30));
        subIntf si = (a,b)->{System.out.println("this is sub inteface");
    return a -b;};
        int a = si.sub(20, 10);
        System.out.println("a: "+a);
        LambdaExpDemo lmd = new LambdaExpDemo();
        lmd.showSub((m,n)->{System.out.println("Passed in method");
    return m-n;}, 300, 100);*/
    }
    
}
