import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args)
    {
         Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        int [][] arr = new int[n][m];
        for(int i = 0; i < arr.length; i++)
        {
            for(int j = 0; j < arr[0].length; j++)
            {
                arr[i][j] = scn.nextInt();
            }
        }
        int ans = maxGoldTabu(arr);
        System.out.println(ans);
    /*    int ans = Integer.MIN_VALUE;
        for(int i = 0 ; i < arr.length; i++)
        {
            int t = maxGold(arr, i,0,n-1, m-1);
            if(t > ans)
            {
                ans = t;
            }
        }
        System.out.println(ans);*/
    }
    public static int maxGoldTabu(int [][] arr)
    {
        int n = arr.length;
        int m = arr[0].length;
        int [][] dp = new int[n][m];
        for(int j = m - 1; j >= 0 ; j--)
        {
            for(int i = 0; i < n; i++)
            {
                if(j == m-1)
                {
                    dp[i][j] = arr[i][j];
                }
                else{
                    int tempRes = Integer.MIN_VALUE;
                    if(i - 1 >= 0 && j + 1 <m)
                    {
                        tempRes = Math.max(tempRes, dp[i-1][j +1]);
                    }
                    if(j + 1 < m)
                    {
                        tempRes = Math.max(tempRes, dp[i][j + 1]);
                    }
                    if(i + 1 < n && j + 1 <m)
                    {
                        tempRes = Math.max(tempRes, dp[i + 1][j + 1]);
                    }
                    dp[i][j] = arr[i][j] + tempRes;
                }
            }
        }
        int ans = Integer.MIN_VALUE;
        for(int i = 0 ; i <n ; i++)
        {
            ans = Math.max(dp[i][0],ans);
        }
        return ans;
    }
    public static int maxGold(int [][] arr, int sr, int sc, int dr, int dc)
    {
        if(sc == dc)
        {
            return arr[sr][sc];
        }
        int ans = Integer.MIN_VALUE;
        if(sr-1 >= 0 && sc + 1 <= dc)
        {
            int t = maxGold(arr, sr-1,sc+1,dr,dc);
            if(t != Integer.MIN_VALUE)
            {
                ans = Math.max(t + arr[sr][sc], ans);
            }
        }
        if(sc + 1 <= dc)
        {
            int t = maxGold(arr, sr,sc+1,dr,dc);
            if(t != Integer.MIN_VALUE)
            {
                ans = Math.max(t + arr[sr][sc], ans);
            }
        }
        if(sr + 1 <= dr && sc + 1 <= dc)
        {
            int t = maxGold(arr, sr+1,sc+1,dr,dc);
            if(t != Integer.MIN_VALUE)
            {
                ans = Math.max(t + arr[sr][sc], ans);
            }
        }
        return ans;
    }
    
}