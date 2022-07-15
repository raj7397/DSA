import java.io.*;
import java.util.*;

public class Main2 {
        static int [][] dir = {{0, 1},{1, 0},{1, 1}};
        static String [] dirN = {"h", "v","d"};

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();

        printMazePaths(0,0,n-1,m-1, "");


    }

    // sr - source row
    // sc - source column
    // dr - destination row
    // dc - destination column
    public static void printMazePaths(int sr, int sc, int dr, int dc, String psf) {
     //   System.out.println("sr : "+sr+ " sc: "+sc+" dr: "+dr+" dc: "+dc);
        if(sr == dr && sc == dc)
        {
            System.out.println(psf);
            return;

        }
        for(int d = 0; d < dir.length; d++)
        {
            for(int j = 1;j <= Math.max(dr,dc); j++)
            {
                int r = sr + (j*dir[d][0]);
                int c = sc + (j*dir[d][1]);
                if(r >=0 && r <= dr && c >=0 && c <= dc)
                {
                    printMazePaths(r, c, dr, dc, psf + dirN[d] + j);
                }
            }
        }
        
    }

}