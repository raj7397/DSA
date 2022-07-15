import java.io.*;
import java.util.*;
class ClimbWithMinMoves{
    public static void main(String [] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr = new int[n];
        for(int i = 0; i < arr.length; i++)
        {
            arr[i] = scn.nextInt();
        }
        int ans = minJumpsRec(arr, 0,n);

        System.out.println(ans);
        int [] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        int ansM = minJumpsMemo(arr,0,n,dp);
        
        System.out.println(ansM);
    }
    public static int minJumpsMemo(int [] arr ,int idx, int n, int [] dp)
    {
        if(idx == n)
        {
            dp[idx] = 0;
            return dp[idx];
            //return 0;
        }
        if(dp[idx] != -1)
            return dp[idx];
        int ans = Integer.MAX_VALUE;
        for(int j = 1; j <= arr[idx] && j + idx <= n; j++)
        {
            int recAns = minJumpsMemo(arr, j + idx, n,dp);
            if(recAns != Integer.MAX_VALUE)
            {
                ans = Math.min(recAns + 1, ans);
            }
        }
        dp[idx] = ans;
        return dp[idx];
    }
    public static int minJumpsRec(int [] arr ,int idx, int n)
    {
        if(idx == n)
        {
            return 0;
        }

        int ans = Integer.MAX_VALUE;
        for(int j = 1; j <= arr[idx] && j + idx <= n; j++)
        {
            int recAns = minJumpsRec(arr, j + idx, n);
            if(recAns != Integer.MAX_VALUE)
            {
                ans = Math.min(recAns + 1, ans);
            }
        }
        return ans;
    }
}