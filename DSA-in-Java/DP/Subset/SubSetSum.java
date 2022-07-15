import java.io.*;
import java.util.*;

public class SubSetSum{
    public static void main(String [] args)
    {
        int [] arr = { 68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46};
       // Scanner scn = new Scanner(System.in);
        //int n = scn.nextInt();
        //int [] arr = new int[n];
      /*  for(int i = 0; i < n; i++)
        {
            arr[i] = scn.nextInt();
        }*/
        int n = arr.length;
        int target = 282;
        //boolean ansR = subSubsetSumRec(arr, n, target);
        //System.out.println(ansR);
        System.out.println("Before memo");
      //  boolean [][] dp = new boolean[n+1][target+1];
        //boolean ansM = subSubsetSumMemo(arr, n, target, dp);
        //System.out.println(ansM);
        boolean ansT = subSubsetSumTabu(arr, target);
        System.out.println(ansT);
    }
    public static boolean subSubsetSumRec(int [] arr , int n, int sum)
    {
        if(sum == 0)
        {
            return true;
        }
        if(n == 0)
        {
            return false;
        }
        if(arr[n-1] <= sum)
        {
            if(subSubsetSumRec(arr, n - 1, sum - arr[n-1]))
            {
                return true;
            }
        }
        return subSubsetSumRec(arr, n - 1, sum);
    }
  public static boolean subSubsetSumMemo(int [] arr , int n, int sum , boolean [][] dp)
    {
        if(sum == 0)
        {
            dp[n][sum] = true;
            return dp[n][sum];
        }
        if(n == 0)
        {
            dp[n][sum] = false;
            return dp[n][sum];
            //return false;
        }
        if(dp[n][sum] == true)
            return dp[n][sum];
        if(arr[n-1] <= sum)
        {
            if(subSubsetSumMemo(arr, n - 1, sum - arr[n-1], dp))
            {
                dp[n][sum] = true;
                return dp[n][sum];
            }
        }
        boolean recAns =  subSubsetSumMemo(arr, n - 1, sum, dp);
        dp[n][sum] = recAns;
        return dp[n][sum];
    }
    public static boolean subSubsetSumTabu(int [] arr, int sum)
    {
        int n = arr.length;
        boolean [][] dp = new boolean[n + 1][sum + 1];
        for(int i = 0; i < n+1; i++)
        {
            for(int j = 0; j < sum + 1; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = true;
                }
                else if(j == 0)
                {
                    dp[i][j] = true;
                }
                else if(i == 0)
                {
                    dp[i][j] = false;
                }
                else{
                    boolean incl = false;
                    if(arr[i-1] <= j)
                    {
                        incl = dp[i-1][j - arr[i-1]];
                    }
                    boolean excl = dp[i -1][j];
                    dp[i][j] = incl || excl;

                }

            }
        }
        return dp[n][sum];
    }
}