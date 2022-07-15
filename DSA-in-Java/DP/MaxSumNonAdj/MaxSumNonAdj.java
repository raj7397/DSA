import java.util.*;
import java.io.*;

public class MaxSumNonAdj{
    public static void main(String [] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr = new int[n];
        for(int i = 0; i < arr.length; i++)
        {
            arr[i] = scn.nextInt();
        }
        int ans = maxSumNonAdjRec(arr,0);
        System.out.println(ans);
    }
    public static int maxSumNonAdjRec(int [] arr , int idx)
    {
        if(idx >= arr.length)
        {
            return 0;
        }
        int ans = arr[idx] + maxSumNonAdjRec(arr, idx + 2);
        int excl = maxSumNonAdjRec(arr, idx + 1);
        return Math.max(ans,excl);

    }
}