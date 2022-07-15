import java.util.*;
import java.io.*;

public class LongesetSubArrayCommonSpan{
    public static void main(String [] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = scn.nextInt();
        }
        int m = scn.nextInt();
        int [] arr2 = new int[m];
        for(int i = 0; i < m; i++)
        {
            arr2[i] = scn.nextInt();
        }
        int ans = longestCommonSpan(arr, arr2);
        System.out.println("ans: "+ ans);
        //printUnion(arr,arr2);
       // printIntersection(arr,arr2);
    }
    public static int longestCommonSpan(int [] arr1, int [] arr2)
    {
        int n = arr1.length;
        int [] temp = new int[n];
        for(int i = 0; i < n; i++)
        {
            temp[i] = arr1[i] - arr2[i];
        }
        HashMap<Integer,Integer> hm = new HashMap<>();
        int preSum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            preSum = preSum + temp[i];
            if(preSum == 0)
            {
                ans = Math.max(ans, i + 1);
            }
            if(hm.containsKey(preSum - 0))
            {
                ans = Math.max(ans, i - hm.get(preSum - 0));
            }
            if(hm.containsKey(preSum) == false)
                hm.put(preSum, i);
        }
        return ans;
    }
    public static void printUnion(int [] arr1, int [] arr2)
    {
        HashSet<Integer> hs = new HashSet<>();
        for(int i = 0; i < arr1.length; i++)
        {
            hs.add(arr1[i]);
        }
        for(int i = 0; i < arr2.length; i++)
        {
            hs.add(arr2[i]);
        }
        for(Integer ele : hs)
        {
            System.out.print(ele + " ");
        }
        System.out.println();
    }
    public static void printIntersection(int [] arr1 , int [] arr2)
    {
        HashSet<Integer> hs = new HashSet<>();
        for(int i = 0; i < arr1.length; i++)
        {
            hs.add(arr1[i]);
        }
        for(int i = 0; i < arr2.length; i++)
        {
            if(hs.contains(arr2[i]))
            {
                System.out.println(arr2[i]);
                hs.remove(arr2[i]);
            }
        }
    }
    
}