import javax.swing.RootPaneContainer;

class GenericExp<T,S>
{
    private T name;
    private S rollno;
    GenericExp(T name, S rollno)
    {
        this.name = name;
        this.rollno = rollno;
    }
    public void showDetails()
    {
        System.out.println("name:--> "+name);
        System.out.println("rollno:-->"+rollno);
    }
    public S getRoll()
    {
        return rollno;
    }
    public <N> int getN( N x)
    {
        //N x = 10;
        return 10;
    }
    public <K> int count(K [] arr, K x)
    {
        int res = 0;
        for(int i = 0; i < arr.length; i++)
        {
            if(arr[i] == x)
                res++;
        }
        return res;
    }

}



public class GenericsDemo {
public static void main(String[] args) {
    GenericExp<String, Integer> ge = new GenericExp<String, Integer>("Rajkalash",1001);
    Integer [] arr={10,20,40,30,10,10,20};
    String [] strArr = {"Rajkalash", "Rajkalash","Sumi","Koushilya"};
    System.out.println(ge.count(strArr, "Rajkalash"));
    System.out.println(ge.count(arr,10));
    ge.showDetails();
    System.out.println(ge.getRoll());
    System.out.println(ge.getN(20));
}
    
}
