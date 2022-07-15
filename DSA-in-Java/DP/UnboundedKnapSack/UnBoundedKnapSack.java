import java.io.*;
import java.util.*;

public class UnBoundedKnapSack{
    public static void main(String [] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] val = new int[n];
        for(int i = 0; i < n; i++)
        {
            val[i] = scn.nextInt();
        }
        int [] wt = new int[n];
        for(int i = 0; i < n; i++)
        {
            wt[i] = scn.nextInt();
        }
        int cap = scn.nextInt();
        int ansR = zeroOneKnapSackRec(wt, val,n, cap);
        System.out.println(ansR);
        int [][] dp = new int[n + 1][cap + 1];
        for(int i = 0; i < n+1; i++)
        {
            Arrays.fill(dp[i],-1);
        }
        int ansM = zeroOneKnapSackMemo(wt, val,n, cap,dp);
        System.out.println(ansM);
       /* System.out.println("Dp display");
        for(int i = 0; i < dp.length; i++)
        {
            for(int j = 0; j < dp[0].length; j++)
            {
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }*/
        int ansT = zeroOneKnapSackTabu(wt, val, cap);
        System.out.println(ansT);
      /*  int [][] dp = new int[n+1][target+1];
        for(int i = 0; i < n + 1; i++)
        {
            Arrays.fill(dp[i], -1);
        }
        int ansM = coinChangeCombMemo(arr, n, target, dp);
        System.out.println(ansM);
        int ansT = coinChangeCombTabu(arr, target);
        System.out.println(ansT);
        int ansMinCoinR = minCoinChangeCombRec(arr, n, target);
        System.out.println(ansMinCoinR);
        int ansMaxCoinR = maxCoinChangeCombRec(arr, n, target);
        System.out.println(ansMaxCoinR);*/
    }
    public static int zeroOneKnapSackTabu(int [] wt, int [] val, int cap)
    {
        int n = wt.length;
        int [][] dp = new int[n + 1][cap + 1];
        for(int i = 0 ; i < n+1; i++)
        {
            for(int j = 0 ; j < cap+1; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else{
                    int ans = dp[i-1][j];
                    if(wt[i - 1] <= j)
                    {
                        int incl = val[i-1] + dp[i][j - wt[i - 1]];
                        ans = Math.max(incl, ans);
                    }
                    dp[i][j] = ans;
                }
    
            }
        }
        return dp[n][cap];
    }
    public static int zeroOneKnapSackMemo(int [] wt, int [] val, int n, int cap,int [][] dp)
    {
        if(cap == 0 || n == 0)
        {
            dp[n][cap] = 0;
            return dp[n][cap];
        }
        if(dp[n][cap] != -1)
            return dp[n][cap];

        int ans = 0;
        if(wt[n - 1] <= cap)
        {
            int incl = val[n-1] + zeroOneKnapSackMemo(wt, val, n , cap - wt[n - 1], dp);
            ans = Math.max(ans, incl);
        }
        int excl = zeroOneKnapSackMemo(wt, val, n - 1, cap,dp);
        ans = Math.max(ans, excl);
        dp[n][cap] = ans;
        return dp[n][cap];
    }
    public static int zeroOneKnapSackRec(int [] wt, int [] val, int n, int cap)
    {
        if(cap == 0)
        {
            return 0;
        }
        if(n == 0)
        {
            return 0;
        }
        int ans = 0;
        if(wt[n - 1] <= cap)
        {
            int incl = val[n-1] + zeroOneKnapSackRec(wt, val, n, cap - wt[n - 1]);
            ans = Math.max(ans, incl);
        }
        int excl = zeroOneKnapSackRec(wt, val, n - 1, cap);
        ans = Math.max(ans, excl);
        return ans;
    }
}