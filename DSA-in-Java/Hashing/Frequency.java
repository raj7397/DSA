import java.util.*;
import java.io.*;

public class Frequency{
    public static void main(String [] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = scn.nextInt();
        }
        printFrequency(arr);
    }
    public static void printFrequency(int [] arr)
    {
        HashMap<Integer, Integer> mp = new HashMap<>();
       // TreeMap<Integer,Integer> mp = new TreeMap<>();
        for(int i = 0; i < arr.length; i++)
        {
            if(mp.containsKey(arr[i]))
            {
                int val = mp.get(arr[i]);
                val = val + 1;
                mp.put(arr[i], val);
            }
            else{
                mp.put(arr[i],1);
            }
        }
        for(Integer ele : mp.keySet())
        {
            System.out.println("key: " + ele + " value: "+mp.get(ele));
        }
        System.out.println("----------------------------------------------");
        for(Map.Entry<Integer,Integer> ele: mp.entrySet())
        {
            System.out.println("Key: "+ ele.getKey() + " Value: "+ ele.getValue());
        }
    }
}