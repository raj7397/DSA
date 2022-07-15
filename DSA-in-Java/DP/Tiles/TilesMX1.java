import java.util.*;
import java.io.*;

public class TilesMX1{
    public static void main(String [] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        int ans = waysRec(n , m);
        System.out.println(ans);
         int [] dp = new int[n+1];
        Arrays.fill(dp , -1);
        int ansM = waysMemo(n ,m, dp);
       System.out.println(ansM);
      /*  int ansT = waysTabu(n);
        System.out.println(ansT);*/
    }
    public static int waysMemo(int n , int m, int [] dp)
    {
        if(n == m)
        {
            dp[n] = 2;
            return dp[n];
        }
        else if(m > n)
        {
            dp[n] = 1;
            return dp[n];
        }
        int ans = waysMemo(n - 1, m , dp);
        int ans2 = waysMemo(n - m, m, dp);
        dp[n] = ans + ans2;
        return dp[n];

    }
     public static int waysRec(int n , int m)
    {
        if(n == m)
        {
            return 2;
        }
        else if(m > n)
        {
            return 1;
        }
        int ans = waysRec(n - 1, m);
        int ans2 = waysRec(n - m, m);
        return ans + ans2;

    }
}
