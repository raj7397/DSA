import java.io.*;
import java.util.*;

public class MapEx{
    public static void main(String [] args)
    {
        TreeMap<Integer, Integer> m = new TreeMap<>();
        m.put(50,100);
        System.out.println(m.get(50));
        m.put(10,30);
        System.out.println(m.get(10));
        m.put(50, 5000);
        System.out.println("key: "+ m.get(50)+ " size: " + m.size());
    }
}