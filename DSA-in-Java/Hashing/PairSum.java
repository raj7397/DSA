import java.util.*;
import java.io.*;

public class PairSum{
    public static void main(String [] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = scn.nextInt();
        }
        int sum = scn.nextInt();
        boolean ans = pairSum(arr, sum);
        System.out.println("ans: "+ ans);
        //printFrequency(arr);
    }
    public static boolean pairSum(int [] arr , int sum)
    {
        HashSet<Integer>hs = new HashSet<>();
        for(int i = 0; i < arr.length; i++)
        {
            if(hs.contains(sum - arr[i]))
                return true;
            hs.add(arr[i]);
        }
        return false;
    }
  
}