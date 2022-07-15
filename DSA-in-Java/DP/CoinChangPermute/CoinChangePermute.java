import java.io.*;
import java.util.*;

public class CoinChangePermute{
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
       int ansR = coinChangePermuteRec(arr, target);
        System.out.println("ansR: "+ ansR);
      /*  int [][] dp = new int[n+1][target+1];
        for(int i = 0; i < n + 1; i++)
        {
            Arrays.fill(dp[i], -1);
        }
        int ansM = coinChangeCombMemo(arr, n, target, dp);
        System.out.println(ansM);
        int ansT = coinChangeCombTabu(arr, target);
        System.out.println(ansT);
       /* int ansMinCoinR = minCoinChangeCombRec(arr, n, target);
        System.out.println(ansMinCoinR);
        int ansMaxCoinR = maxCoinChangeCombRec(arr, n, target);
        System.out.println(ansMaxCoinR);*/
    }
    public static int coinChangePermuteRec(int [] arr, int sum)
    {
        if(sum == 0)
        {
            return 1;
        }
     //   if(sum < 0)
       //     return 0;
        int ans = 0;
        for(int i = 0; i < arr.length; i++)
        {
            if(arr[i] <= sum)
                 ans = ans + coinChangePermuteRec(arr, sum - arr[i]);
        }
        return ans;
    }
}