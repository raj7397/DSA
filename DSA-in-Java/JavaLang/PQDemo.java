import java.util.*;

public class PQDemo{
    public static class pair{
        int val1;
        int val2;
        pair(int val1, int val2)
        {
            this.val1 = val1;
            this.val2 = val2;
        }
    }
    public static void main(String[] args)
    {
        PriorityQueue<pair> pq = new PriorityQueue<>((a,b)->{
            return b.val2 - a.val2;
        });

        pq.add(new pair(10,2));
        pq.add(new pair(5,20));
        pq.add(new pair(500,-1));
        pq.add(new pair(-1, 200));
        while(pq.size() > 0)
        {
            pair rem = pq.peek();
            pq.remove();
            System.out.println("val1: "+rem.val1 + " val2: "+rem.val2);
        }
    }
}