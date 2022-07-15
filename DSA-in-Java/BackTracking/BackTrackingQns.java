import java.io.*;
import java.util.*;

public class BackTrackingQns{
    public static Scanner scn = new Scanner(System.in);
    public static int [][] dir = {{-1, 0}, {0, -1}, {1,0},{0,1}};
    public static String [] dirN = {"t","l","d","r"};
    public static void main(String [] args)
    {
        solveTargetSumSubSet();
       // solveFloodFill2();
       // solveFloodFill1();
    }
    public static void solveTargetSumSubSet()
    {
        int n = scn.nextInt();
        int [] arr = new int[n];
        for(int i = 0 ;i < arr.length; i++)
        {
            arr[i] = scn.nextInt();
        }
        int sum = scn.nextInt();
        printTargetSumSubset(arr, 0,"",sum);
    }
    public static void printTargetSumSubset(int [] arr ,int idx , String asf, int sum)
    {
        if(sum == 0)
        {
            System.out.println(asf + ".");
            return;
        }
        if(idx >= arr.length)
        {
            return;
        }
        if(arr[idx] <= sum)
        {
            printTargetSumSubset(arr, idx + 1, asf + arr[idx] +" ,", sum - arr[idx]);
        }
        printTargetSumSubset(arr, idx + 1, asf, sum);
        
    }
    public static void solveFloodFill2()
    {
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
        floodFill2(arr, 0, 0, "");
    }
    public static  void floodFill2(int [][] arr, int sr, int sc, String path)
    {
        if(sr == arr.length - 1 && sc == arr[0].length - 1)
        {
            System.out.println(path);
            return;
        }
        arr[sr][sc] = 1;
        for(int i = 0; i < dir.length ;i++)
        {
            int r = sr + dir[i][0];
            int c = sc + dir[i][1];
            if(r >= 0 && r < arr.length && c >= 0 && c < arr[0].length && arr[r][c] != 1)
            {
                floodFill2(arr, r, c, path + dirN[i]);
            }
        }
        arr[sr][sc] = 0;
    }
    
    public static void solveFloodFill1()
    {
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
        int [][] visited = new int [n][m];
        floodFill1(arr, 0, 0, "",visited);
    }
    public static void display(int [][] arr)
    {
        for(int i = 0; i < arr.length; i++)
        {
            for(int j = 0 ; j < arr[0].length; j++)
            {
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void floodFill1(int [][] arr,int sr, int sc, String path, int [][] visited)
    {
//	System.out.println("sr: "+ sr+" sc: "+sc);
     //   System.out.println("floodfill");
        if(sr < 0 || sr >= arr.length || sc < 0 || sc >= arr[0].length || arr[sr][sc] == 1 || visited[sr][sc] == 1)
        {
            return;
        }
        if(sr == arr.length -1  && sc == arr[0].length - 1)
        {
            System.out.println(path);
            System.out.println("---------------------------");
            display(visited);
            System.out.println("---------------------------");
            return ;
        }
        visited[sr][sc] = 1;
        floodFill1(arr, sr-1, sc,path + "t", visited);
        floodFill1(arr , sr , sc - 1, path + "l", visited);
        floodFill1(arr, sr + 1, sc, path + "d",visited);
        floodFill1(arr, sr, sc+1 , path + "r", visited);
        visited[sr][sc] = 0;
    }
}

