import java.util.*;
import java.io.*;
import java.lang.*;
public class CountNK{
    public static void main(String [] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = scn.nextInt();
        }
        int k = scn.nextInt();
        printNK(arr,k);
       // printDistinctEleWinowK(arr,k);
        //printFrequency(arr);
    }
    public static void printNK(int [] arr, int k)
    {
        HashMap<Integer,Integer> hm = new HashMap<>();
        for(int i = 0; i < arr.length; i++)
        {
            if(hm.containsKey(arr[i]))
            {
                int val = hm.get(arr[i]);
                val++;
                hm.put(arr[i],val);
            }
            else if(hm.size() < k - 1)
            {
                hm.put(arr[i],1);
            }
            else{
                for(Map.Entry x:hm.entrySet())
                {
                    Integer c=(Integer)x.getValue();
                    hm.put((Integer)x.getKey(),c - 1);
                    if((Integer)x.getKey()==0)
                        hm.remove(x.getKey());                    
              }

            }                
        }

        int n = arr.length;
          for(Map.Entry x:hm.entrySet()){
            int count=0;
            for(int i=0;i<n;i++){
                if((Integer)x.getKey()==arr[i])
                    count++;
            
           }
            if(count>n/k)
                System.out.print(x.getKey()+" ");
        }
    }
}