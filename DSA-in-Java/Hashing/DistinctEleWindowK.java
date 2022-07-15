import java.util.*;
import java.io.*;

public class DistinctEleWindowK{
    public static void main(String [] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = scn.nextInt();
        }
        int k = scn.nextInt();
        printDistinctEleWinowK(arr,k);
        //printFrequency(arr);
    }
    public static void printDistinctEleWinowK(int [] arr, int k)
    {
        HashMap<Integer,Integer> hm = new HashMap<>();
        for(int i = 0; i < k ; i++)
        {
           hm.put(arr[i],hm.getOrDefault(arr[i],0) +1);
        }
        System.out.print(hm.size()+ " ");
        for(int i = k ; i < arr.length;i++)
        {
            int val = hm.get(arr[i - k]);
            val--;
            if(val == 0)
                hm.remove(arr[i - k]);
            else
                hm.put(arr[i - k],val);
            hm.put(arr[i], hm.getOrDefault(arr[i],0) + 1);
            System.out.print(hm.size() + " ");
        }
        System.out.println();
 /*       HashMap<Integer,Integer> hm = new HashMap<>();
        for(int i = 0; i < k; i++)
        {
            if(hm.containsKey(arr[i]))
            {
                int val = hm.get(arr[i]);
                val = val + 1;
                hm.put(arr[i], val);
            }
            else{
                hm.put(arr[i],1);
            }
        }
        System.out.print(hm.size() +" ");
        for(int i = k; i < arr.length; i++)
        {
            int val = hm.get(arr[i - k]);
            val = val -1;
            if(val == 0)
                hm.remove(arr[i - k]);
            else{
                hm.put(arr[i - k], val);
            }
            if(hm.containsKey(arr[i]))
            {
                int val2 = hm.get(arr[i]);
                val2 = val2 + 1;
                hm.put(arr[i],val2);
            }
            else{
                hm.put(arr[i],1);
            }
            System.out.print(hm.size()+ " ");
        }
        System.out.println();*/
    }
 
}