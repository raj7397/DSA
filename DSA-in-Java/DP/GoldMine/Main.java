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
        int ans = Integer.MIN_VALUE;
        for(int i = 0 ; i < arr.length; i++)
        {
            int t = maxGold(arr, i,0,n-1, m-1);
            if(t > ans)
            {
                ans = t;
            }
        }
        System.out.println(ans);
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