import java.util.Scanner;

public class CoinChangeSeries {

    public static int coinChangeTotals(int [] arr , int target, String asf)
    {
        if(target == 0)
        {
            System.out.println(asf);
            return 1;
        }
            //return 1;
        int ans = 0;
        for(int i = 0; i < arr.length;i++)
        {
            if(target - arr[i] >= 0)
            {
                ans += coinChangeTotals(arr, target - arr[i], asf + arr[i]+" ");
            }
        }
        return ans;
    }
    public static void coinChangePermute()
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = scn.nextInt();
        }
        int target = scn.nextInt();
        System.out.println(coinChangeTotals(arr,target, ""));
    }
    public static void coinChangePermute2()
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr =new int[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = scn.nextInt();
        }
        int target = scn.nextInt();
        System.out.println(printAllWays(arr,target, ""));
    }
    public static int printAllWays(int [] arr, int target,  String asf){
        if(target == 0)
        {
            System.out.println(asf);
            return 1;
        }
        int count = 0;
        for(int i = 0; i < arr.length;i++)
        {
            if(target- arr[i] >= 0)
            {
                count+= printAllWays(arr, target - arr[i], asf+ arr[i]);
            }
        }
        return count;
    }
    public static int printCoinChangeinfSupplyComb(int [] arr, int target,String asf, int idx)
    {
        if(target == 0)
        {
            System.out.println(asf);
            return 1;
        }
        int ans = 0;
        for(int i = idx; i< arr.length;i++)
        {
            if(target - arr[i] >= 0)
            {
                ans+= printCoinChangeinfSupplyComb(arr, target - arr[i], asf + arr[i], i);
            }
        }
        return ans;

    }
    public static void coinChangeinfComb()
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr =new int[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = scn.nextInt();
        }
        int target = scn.nextInt();
        System.out.println(printCoinChangeinfSupplyComb(arr,target,"",0));
        
    }
    public static int printCoinChangePermuteSingleCoin(int [] arr, int target,boolean [] visited,String asf)
    {
        if(target == 0)
        {
            System.out.println(asf);
            return 1;
        }
        int count = 0;
        for(int i = 0; i < arr.length;i++)
        {
            if(target - arr[i] >= 0 && !visited[i])
            {
                visited[i] = true;
                count+= printCoinChangePermuteSingleCoin(arr, target - arr[i], visited, asf + arr[i]);
                visited[i] = false;
            }
        }
        return count;
    }
    public static void coinChangePermuteSingleCoin()
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = scn.nextInt();
        }
        int target = scn.nextInt();
        boolean [] visited = new boolean[n];
        System.err.println(printCoinChangePermuteSingleCoin(arr,target,visited,""));
    }
    public static void coinChangePermuteSingleCoin2()
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr = new int[n];
        for(int i = 0; i < n;i++)
        {
            arr[i] = scn.nextInt();
        }
        int target = scn.nextInt();
        System.out.println(coinChangePermuteSingleCoin2(arr,target,""));
    }
    public static int coinChangePermuteSingleCoin2(int [] arr, int target, String asf)
    {
        if(target == 0)
        {
            System.out.println(asf);
            return 1;
        }
        int count = 0;
        for(int i = 0; i< arr.length;i++)
        {
            if(arr[i] > 0 && target - arr[i] >= 0)
            {
                int val = arr[i];
                arr[i] = -arr[i];
                count += coinChangePermuteSingleCoin2(arr, target - val, asf + val);
                arr[i] = -arr[i];
            }
        }
        return count;
    }
    public static int printCoinChangeCombiSingleCoin(int [] arr, int idx, String asf,int target)
    {
        if(target == 0)
        {
            System.out.println(asf);
            return 1;
        }
        if(idx == arr.length)
        {
            return  0;
        }
        int count = 0;
        for(int i = idx ; i < arr.length;i++)
        {
            count+= printCoinChangeCombiSingleCoin(arr, i+1, asf+arr[i], target - arr[i]);
        }
        return count;
    }
    public static void coinChangeCombiSingleCoin()
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr = new int[n];
        for(int i = 0; i< n;i++)
        {
            arr[i] = scn.nextInt();
        }
        int target = scn.nextInt();
        System.out.println(printCoinChangeCombiSingleCoin(arr,0,"",target));
    }
    public static void main(String[] args) {
        coinChangeCombiSingleCoin();
       // coinChangePermuteSingleCoin2();
      //  coinChangePermuteSingleCoin();
       // coinChangeinfComb();
      //  coinChangePermute();
      //coinChangePermute2();
        
    }
    
}
