import java.util.*;
import java.io.*;

public class Tiles{
    public static void main(String [] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int ans = waysRec(n);
        System.out.println(ans);
        int [] dp = new int[n+1];
        Arrays.fill(dp , -1);
        int ansM = waysMemo(n , dp);
        System.out.println(ansM);
        int ansT = waysTabu(n);
        System.out.println(ansT);
    }
    public static int waysTabu(int n)
    {
        int a = 1;
        int b = 2;
        int c = 0;
        for(int i = 3; i <= n; i++)
        {
             c = a+b;
             a = b;
             b = c;

        }
        return c;
    }
    public static int waysMemo(int n, int [] dp)
    {
        if(n <= 2)
        {
            dp[n] = n;
            return dp[n];
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
           // return n;


        int ans1 =waysMemo(n - 1, dp);
        int ans2 = waysMemo(n - 2,dp);
        dp[n] = ans1+ans2;
        return dp[n];
    }
    public static int waysRec(int n)
    {
        if(n <= 2)
            return n;


        int ans1 =waysRec(n - 1);
        int ans2 = waysRec(n - 2);
        return ans1 + ans2;
    }
}