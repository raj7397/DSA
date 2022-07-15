import java.util.*;
import java.io.*;

public class LongestConsecutiveSubSeq{
    public static void main(String [] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = scn.nextInt();
        }
        int ans = longConsecutiveSubSeq(arr);
        System.out.println("ans: "+ ans);

    }
    public static int longConsecutiveSubSeq(int [] arr)
    {
        HashSet<Integer> hs = new HashSet<>();
        for(int i = 0; i < arr.length; i++)
            hs.add(arr[i]);
        int ans = 1;
        for(int i = 0; i < arr.length; i++)
        {
            if(hs.contains(arr[i] - 1) == false)
            {
                int count = 1;
                while(hs.contains(arr[i] + count))
                    count++;
                ans = Math.max(ans, count);
            }
        }
        return ans;
    }
   
 
  
}