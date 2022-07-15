import java.util.Arrays;
import java.util.Comparator;



class Point{
    int x;
    int y;
    Point(int x, int y)
    {
        this.x = x;
        this.y = y;
    }
}
class myComp implements Comparator<Point>{
    public int compare(Point a,Point b)
    {
        return b.x - a.x;
        /*
        
        int ret = a.x - b.x;
        if(a.x > b.x)
        {
            System.out.println("ret: "+ret);
            System.out.println("(-ve)->>a.x:--> "+a.x+" b.x:-->"+b.x);
            return -90;
        }
        else if(a.x < b.x)
        {
            System.out.println("ret: "+ret);
            System.out.println("(+ve)-->>a.x:--> "+a.x+" b.x:-->"+b.x);
            return 100;
        }
        else {
            System.out.println("ret: "+ret);
            System.out.println("(==)-->a.x:--> "+a.x+" b.x:-->"+b.x);
            return 0;
        }*/
    }
}


public class ComparatorDemo {
    public static void main(String[] args) {
         Point [] arr = { new Point(100,100),new Point(200,500),new Point(300,200)};
         Comparator<Point> comp = new Comparator<>() {
             public int compare(Point a, Point b)
             {
                 return b.x - a.x;
             }
             
         };
       /* Arrays.sort(arr, new Comparator<Point>() {
            public int compare(Point a, Point b)
            {
                return a.x - b.x;
            }
            
        });        */
        Arrays.sort(arr, ( a ,b)->{ return a.x - b.x;});
        System.out.println("After sorting :");
        for(int i = 0; i < arr.length;i++)
        {
            Point p = arr[i];
            System.out.println("a.x: "+p.x+" b.x: "+p.y);
        }
    }
    
}
