import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Iterator;

public class DequeDemo{
    public static void main(String[] args) {
        ArrayDeque<Integer> dq = new ArrayDeque<>();
        dq.add(10);
        dq.add(20);
        dq.add(30);
      //  dq.push(40);
        int x = dq.getLast();
        //int y = dq.pop();
        int y = 100;
        System.out.println("x: "+x+" y: "+y);
        Iterator<Integer> it = dq.iterator();
        while(it.hasNext())
        {
            Integer ele = (Integer)it.next();
            System.out.println("ele: "+ele);
        }
        for(Integer ele : dq)
        {
            System.out.println(ele);
        }
        
    }
}