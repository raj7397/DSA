import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        climbStairsMemo(n);
       // int ansR = climbStairsR(n);
        //System.out.println(ansR);
        
        // write your code here
    }
    pubic static void climbStairsMemo(int n)
    {
        int [] dp = new int[n+1];
        Arrays.fill(dp, -1);
        int ans = climbStairsMemoHelper(n,dp);
        System.out.println(ans);
    }
    public static int climbStairsMemoHelper(int n, int [] dp)
    {
        if(n == 0)
        {
            dp[n] = 0;
            return dp[n];
            //return 1;
        }
        
        if(dp[n] != -1)
        {
            return dp[n];
        }
        int ans = 0;
        if(n - 1 >= 0)
        {
            ans = ans + climbStairsMemoHelper(n - 1);
        }
        if(n - 2 >= 0)
        {
            ans = ans + climbStairsMemoHelper(n - 2);
        }
        if(n - 3 >= 0)
        {
            ans = ans + climbStairsMemoHelper(n - 3);
        }
        dp[n] = ans;
        return dp[n];
        //return ans;
    }
    public static int climbStairsR(int n)
    {
        if(n == 0)
        {
            return 1;
        }
        
        int ans = 0;
        if(n - 1 >= 0)
        {
            ans = ans + climbStairsR(n - 1);
        }
        if(n - 2 >= 0)
        {
            ans = ans + climbStairsR(n - 2);
        }
        if(n - 3 >= 0)
        {
            ans = ans + climbStairsR(n - 3);
        }
        return ans;
    }

}