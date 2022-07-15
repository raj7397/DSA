import java.util.ArrayList;
import java.util.Arrays;

public class toArrayExp {
    public static void main(String[] args) {
        ArrayList<Integer> al = new ArrayList<>();
        al.add(10);
        al.add(20);
        al.add(-200);
        Object [] oa = al.toArray();
        int sum = 0;
        for(Object e: oa)
        {
            sum+= (Integer)e;
            System.out.println("e: "+e);
        }

        Integer [] arr = new Integer[al.size()];
        arr = al.toArray(arr);
        sum = 0;
        for(Integer e: arr)
        {
            sum+=e;
            System.out.println("e:-> "+e);
        }
        System.out.println("sum: "+sum);
        Integer [] arr2 = al.toArray(new Integer[0]);
        sum = 0;
        for(int i = 0; i < arr2.length;i++)
        {
            sum+=arr2[i];
            System.out.println("arr2[i]: "+arr2[i]);
        }
        System.out.println("sum: "+sum);

        List<Integer> al2 = Arrays.asList(arr2) ;
        sum = 0;
        for(int i = 0; i < al2.size();i++)
        {
            sum+=al2.get(i);
            System.out.println("ele: "+al2.get(i));
        }
    }
    
}
