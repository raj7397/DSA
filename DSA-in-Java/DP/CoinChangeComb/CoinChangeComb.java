import java.io.*;
import java.util.*;

public class CoinChangeComb{
    public static void main(String [] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = scn.nextInt();
        }
        int target = scn.nextInt();
      /*  int ansR = coinChangeCombRec(arr, n, target);
        System.out.println(ansR);
        int [][] dp = new int[n+1][target+1];
        for(int i = 0; i < n + 1; i++)
        {
            Arrays.fill(dp[i], -1);
        }
        int ansM = coinChangeCombMemo(arr, n, target, dp);
        System.out.println(ansM);*/
        int ansT = coinChangeCombTabu(arr, target);
        System.out.println(ansT);
       /* int ansMinCoinR = minCoinChangeCombRec(arr, n, target);
        System.out.println(ansMinCoinR);
        int ansMaxCoinR = maxCoinChangeCombRec(arr, n, target);
        System.out.println(ansMaxCoinR);*/
    }
    public static int coinChangeCombTabu(int [] arr, int sum)
    {
        int n = arr.length;
        int [] dp = new int [sum + 1];
        dp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < sum + 1; j++)
            {
                if(arr[i] <= j)
                {
                    dp[j] = dp[j] + dp[j - arr[i]];
                }
            }
        }
        return dp[sum];
    }
    public static int maxCoinChangeCombRec(int [] arr, int n, int sum)
    {
        if(sum == 0)
        {
            return 0;
        }
        if(n == 0)
        {
            return Integer.MIN_VALUE;
        }
        int ans = Integer.MIN_VALUE;
        if(arr[n - 1] <= sum)
        {
            int incl = maxCoinChangeCombRec(arr, n, sum - arr[n - 1]);
            if(incl != Integer.MIN_VALUE)
            {
                ans = Math.max(1 + incl, ans);
            }
        }
        int excl = maxCoinChangeCombRec(arr, n - 1, sum);
        if(excl != Integer.MIN_VALUE)
            ans = Math.max(excl,ans);
        return ans;
    }
    /*  public static int coinChangeCombRec(int [] arr, int n, int sum)
    {
        if(sum == 0)
        {
            return 1;
        }
        if(n == 0)
        {
            return 0;
        }
        int ans = 0;
        if(arr[n - 1] <= sum)
        {
            ans = ans + coinChangeCombRec(arr, n, sum - arr[n - 1]);
        }
        ans+= coinChangeCombRec(arr, n - 1, sum);
        return ans;
    }*/
    public static int minCoinChangeCombRec(int [] arr, int n, int sum)
    {
        if(sum == 0)
        {
            return 0;
        }
        if(n == 0)
        {
            return Integer.MAX_VALUE;
        }
        int ans = Integer.MAX_VALUE;
        if(arr[n - 1] <= sum)
        {
            int incl = minCoinChangeCombRec(arr, n, sum - arr[n - 1]);
            if(incl != Integer.MAX_VALUE)
            {
                ans = Math.min(1 + incl, ans);
            }
        }
        int excl = minCoinChangeCombRec(arr, n - 1, sum);
        if(excl != Integer.MAX_VALUE)
            ans = Math.min(excl,ans);
        return ans;
    }
    public static int coinChangeCombRec(int [] arr, int n, int sum)
    {
        if(sum == 0)
        {
            return 1;
        }
        if(n == 0)
        {
            return 0;
        }
        int ans = 0;
        if(arr[n - 1] <= sum)
        {
            ans = ans + coinChangeCombRec(arr, n, sum - arr[n - 1]);
        }
        ans+= coinChangeCombRec(arr, n - 1, sum);
        return ans;
    }
    public static int coinChangeCombMemo(int [] arr, int n, int sum, int [][] dp)
    {
        if(sum == 0)
        {
            dp[n][sum] = 1;
            
            return dp[n][sum];
        }
        if(n == 0)
        {
            dp[n][sum] = 0;
            return dp[n][sum];
        }
        if(dp[n][sum] != -1)
            return dp[n][sum];
        int ans = 0;
        if(arr[n - 1] <= sum)
        {
            ans = ans + coinChangeCombMemo(arr, n, sum - arr[n - 1], dp);
        }
        ans+= coinChangeCombMemo(arr, n - 1, sum, dp);
        dp[n][sum] = ans;
        return dp[n][sum];
    }
}