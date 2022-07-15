import java.util.*;
import java.io.*;

public class HashMapEx{
    public static void main(String [] args)
    {
        HashMap<String, Integer> myMap = new HashMap<>();
        myMap.put("Rajkalash", 33);
        myMap.put("Koushilya", 45);
        myMap.put("Sumitra", 33);
        myMap.put("Rajkamal",32);
        Set<Map.Entry<String, Integer>> st = myMap.entrySet();
        for(Map.Entry<String, Integer> ele: st)
        {
            System.out.println("key: "+ele.getKey()+" value: "+ele.getValue());
        }
        if(myMap.containsKey("Rajkalash"))
        {
            System.out.println(myMap.containsKey("Rajkalash"));
        }
        myMap.put("Rajkalash",333);
        System.out.println("After update:");
        for(Map.Entry<String, Integer> ele: st)
        {
            System.out.println("key: "+ele.getKey()+" value: "+ele.getValue());
        }
        myMap.remove("Rajkalash");
        System.out.println("After remove Rajkalash");
        System.out.println(myMap.containsKey("Rajkalash"));
        for(Map.Entry<String, Integer> ele: myMap.entrySet())
        {
            System.out.println("Key: "+ele.getKey()+" Value: "+ele.getValue());
        }
    }
}