import java.io.*;
import java.util.*;

public class RingRotate {

    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args) throws Exception {
        // write your code here
        int n = scn.nextInt();
        int m = scn.nextInt();
        int [][] arr = new int[n][m];
        input(arr);
        int s = scn.nextInt();
        int r = scn.nextInt();
        ringRotate(arr, s, r);
        display(arr);
    }
    public static void ringRotate(int [][] arr, int s, int r)
    {
        int [] oneD = from2Dto1D(arr,s);
        System.out.println("Before rotate:");
        for(int i = 0; i < oneD.length; i++)
        {
            System.out.print(oneD[i]+" ");
        }
        rotateOneD(oneD, r);
        System.out.println("\nAfter rotate");
        for(int i = 0; i < oneD.length; i++)
        {
            System.out.print(oneD[i]+" ");
        }
        System.out.println();
        fill2Dfrom1D(arr, oneD, s);
        
    }
    public static void fill2Dfrom1D(int [][] arr, int [] oneD, int s)
    {
        int n = arr.length; 
        int m = arr[0].length;
        int top = s - 1;
        int left = s - 1;
        int bottom = n - s;
        int right = m - s;
        int idx = 0;
        for(int i = left; i <= right; i++)
        {
            arr[top][i] = oneD[idx];
            System.out.println("idx: "+ oneD[idx]+" arr: "+arr[top][i]);
            idx++;
        }
        top++;
        for(int i = top; i <= bottom; i++)
        {
            arr[i][right] = oneD[idx];
            idx++;
        }
        right--;
        for(int i = right; i >= left; i--)
        {
            arr[bottom][i] = oneD[idx];
            idx++;
        }
        bottom--;
        for(int i = bottom; i >= top; i--)
        {
            arr[i][left] = oneD[idx];
            idx++;
        }
        left++;
    }
    public static void rotateOneD(int [] arr, int k)
    {
        int n = arr.length;
        k = -k;
        k = (k%n + n)%n;
        
        reverse(arr, 0, n - k -1);
        reverse(arr, n - k, n - 1);
        reverse(arr, 0, n - 1);
        
    }
    public static void reverse(int [] arr, int i, int j)
    {
        while(i <= j)
        {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }
    public static int [] from2Dto1D(int [][] arr, int s)
    {
        int n = arr.length;
        int m = arr[0].length;
        int top = s - 1;
        int left = s - 1;
        int right = m - s;
        int bottom = n - s;
        int size = 2*(right - left + bottom - top);
        int [] oneD = new int[size];
        int idx = 0;
        for(int i = left; i <= right; i++)
        {
            oneD[idx] = arr[top][i];
            idx++;
        }
        top++;
        for(int i = top; i <= bottom; i++)
        {
            oneD[idx] = arr[i][right];
            idx++;
        }
        right--;
        for(int i = right; i >= left; i--)
        {
            oneD[idx] = arr[bottom][i];
            idx++;
        }
        bottom--;
        for(int i = bottom; i >= top; i--)
        {
            oneD[idx] = arr[i][left];
            idx++;
        }
        left++;
        return oneD;
    }
    public static void input(int [][] arr)
    {
        int n = arr.length;
        int m = arr[0].length;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                arr[i][j] = scn.nextInt();
            }
        }
    }
    public static void display(int[][] arr){
        for(int i = 0; i < arr.length; i++){
            for(int j = 0; j < arr[0].length; j++){
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }

}