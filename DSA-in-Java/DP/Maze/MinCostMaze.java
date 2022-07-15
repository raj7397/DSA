import java.io.*;
import java.util.*;
class MinCostMaze{
    public static void main(String [] args)
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
       // int ansR = minCostMaze(arr, 0,0,n-1, m-1);
        //System.out.println(ansR);
        int [][] dp = new int[n][m];
        for(int i = 0; i < n; i++)
        {
            Arrays.fill(dp[i], -1);
        }
        //Arrays.fill(dp, -1);
        int ansM = minCostMazeMemo(arr, 0, 0, n-1, m-1,dp);
        System.out.println(ansM);
        System.out.println("Tabulation: ");
        int ansT = minCostMazeTabu(arr);
        System.out.println(ansT);
    }
    public static int minCostMazeTabu(int [][] arr)
    {
        int n = arr.length;
        int m = arr[0].length;
        int [][] dp = new int[n][m];
        /*for(int i = n-1; i >= 0 ; i--)
        {
            for(int j = m-1 ; j >= 0 ;j--)
            {
                if(i == n-1 && j == m-1)
                {
                    dp[i][j] = arr[i][j];
                }
                else if(i == n-1)
                {
                    dp[i][j] = arr[i][j] + dp[i][j+1];
                }
                else if(j == m-1)
                {
                    dp[i][j] = arr[i][j] + dp[i+1][j];
                }
                else{
                    dp[i][j] = arr[i][j] + Math.min(dp[i][j+1],dp[i+1][j]);
                }
            }
        }*/
             for(int i = n-1; i >= 0; i--)
        {
            for(int j = m-1; j >= 0; j--)
            {
                if(i == n-1 && j == m-1)
                {
                    dp[i][j] = arr[i][j];
                }
                else if(i == n-1)
                {
                    dp[i][j] = arr[i][j] + dp[i][j+1];
                }
                else if(j == m-1)
                {
                    dp[i][j] = arr[i][j] + dp[i+1][j];
                }
                else{
                    int min = Math.min(dp[i][j+1],dp[i+1][j]);
                    dp[i][j] = arr[i][j] + min;
                }
            }
        }
        return dp[0][0];
    }
    public static int minCostMazeMemo(int [][] arr ,int sr, int sc, int dr, int dc , int [][] dp)
    {

        if(sr == dr && sc == dc)
        {
            dp[sr][sc] = arr[sr][sc];
            return dp[sr][sc];
            //return arr[sr][sc];
        }
        if(dp[sr][sc] != -1)
            return dp[sr][sc];
        int ans = Integer.MAX_VALUE;
        if(sc + 1 <= dc)
        {
            int recAns = minCostMazeMemo(arr, sr, sc + 1, dr, dc, dp);
            if(recAns != Integer.MAX_VALUE)
            {
                ans = Math.min(arr[sr][sc]+ recAns, ans);
            }
        }
        if(sr + 1 <= dr)
        {
            int recAns = minCostMazeMemo(arr, sr + 1, sc, dr, dc,dp);
            if(recAns != Integer.MAX_VALUE)
            {
                ans = Math.min(arr[sr][sc]+ recAns, ans);
            }
        }
        dp[sr][sc] = ans;
        return dp[sr][sc];
        //return ans;
    }
    public static int minCostMaze(int [][] arr ,int sr, int sc, int dr, int dc)
    {

        if(sr == dr && sc == dc)
        {
            return arr[sr][sc];
        }
        int ans = Integer.MAX_VALUE;
        if(sc + 1 <= dc)
        {
            int recAns = minCostMaze(arr, sr, sc + 1, dr, dc);
            if(recAns != Integer.MAX_VALUE)
            {
                ans = Math.min(arr[sr][sc]+ recAns, ans);
            }
        }
        if(sr + 1 <= dr)
        {
            int recAns = minCostMaze(arr, sr + 1, sc, dr, dc);
            if(recAns != Integer.MAX_VALUE)
            {
                ans = Math.min(arr[sr][sc]+ recAns, ans);
            }
        }
        return ans;
    }
}