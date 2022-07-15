import java.util.*;
import java.io.*;

public class PrefixSum{
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
      //  int ans = longestSubArrayGivenSum(arr, sum);
        int ans = longestSubArrayEqual01(arr);
        System.out.println("ans: "+ ans);
     //   
       // boolean ans = subArrayWithGivenSum(arr, sum);
        //boolean ans = subArrayWith0Sum(arr);
      //  int sum = scn.nextInt();
        //boolean ans = pairSum(arr, sum);
        //System.out.println("ans: "+ ans);
        //printFrequency(arr);
    }
    public static int longestSubArrayEqual01(int [] arr)
    {
        for(int i = 0; i < arr.length; i++)
        {
            if(arr[i] == 0)
                arr[i] = -1;
        }
        HashMap<Integer, Integer> hm = new HashMap<>();
        int preSum = 0;
        int ans = 0;
        for(int i = 0; i < arr.length; i++)
        {
            preSum += arr[i];
            if(preSum == 0)
            {
                ans = Math.max(ans, i + 1);
            }
            if(hm.containsKey(preSum - 0))
            {
                ans = Math.max(ans, i - hm.get(preSum - 0));
            }
            if(hm.containsKey(preSum) == false)
                hm.put(preSum,i);
        }
        return ans;
    }
    public static int longestSubArrayGivenSum(int [] arr, int sum)
    {
        HashMap<Integer,Integer> hm = new HashMap<>();
        int preSum = 0;
        int ans = 0;
        for(int i = 0; i < arr.length; i++)
        {
            preSum += arr[i];
            if(preSum == sum)
            {
                ans = Math.max(ans, i + 1);
            }
           // boolean temp = hm.containsKey(preSum - sum);
            //System.out.println("containsKey: "+ temp);
            if(hm.containsKey(preSum - sum))
            {
                ans = Math.max(ans, i - hm.get(preSum -sum));
            }
         //   if(hm.containsKey(preSum) == false)
           // {
                hm.put(preSum,i);
           // }
        }
        return ans;
    }
    public static boolean subArrayWithGivenSum(int [] arr , int sum)
    {
        HashSet<Integer> hs = new HashSet<Integer>();
        int preSum = 0;
        for(int i = 0; i < arr.length; i++)
        {
            preSum+= arr[i];
            if(preSum == sum)
                return true;
            if(hs.contains(preSum - sum ))
                return true;
            hs.add(preSum);
        }
        return false;
    }
    public static boolean subArrayWith0Sum(int [] arr)
    {
        HashSet<Integer> hs = new HashSet<>();
        int preSum = 0;
        for(int i = 0; i < arr.length; i++)
        {
            preSum+= arr[i];
            if(preSum == 0)
                return true;
            if(hs.contains(preSum))
                return true;
            hs.add(preSum);
        }
        return false;
    }
 
  
}