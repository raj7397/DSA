import java.io.*;
import java.util.*;
class StairsWithVariableJumps{
    public static void main(String [] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr = new int[n];
        for(int i = 0; i < arr.length; i++)
        {
            arr[i] = scn.nextInt();
        }
        int ans = varJumpsRec(arr, 0,n);
        System.out.println(ans);
        int [] dp = new int [n+1];
        Arrays.fill(dp , -1);
        int ansM = varJumpsMemo(arr, 0, n, dp);
        System.out.println(ansM);
    }
    public static int varJumpsRec(int [] arr, int idx, int n)
    {
        if(idx == arr.length)
        {
            return 1;
        }
        int ans = 0;
        for(int j = 1; j <= arr[idx] && j + idx <= n; j++)
        {
            ans = ans + varJumpsRec(arr, j + idx, n);
        }
        return ans;
    }
 public static int varJumpsMemo(int [] arr, int idx, int n, int [] dp)
    {
        if(idx == arr.length)
        {
            dp[idx] = 1;
            return dp[idx];
            //return 1;
        }
        if(dp[idx] != -1)
            return dp[idx];
        int ans = 0;
        for(int j = 1; j <= arr[idx] && j + idx <= n; j++)
        {
            ans = ans + varJumpsMemo(arr, j + idx, n, dp);
        }
        dp[idx] = ans;
        return dp[idx];
        //return ans;
    }
}