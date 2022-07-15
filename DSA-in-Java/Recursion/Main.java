import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        ArrayList<String> ans = getMazePathsWithJumps(0,0, n-1, m-1);
        System.out.println("jump-1 ans");
        System.out.println(ans);
        ArrayList<String> ans1 = getMazePathsWithJumps1(0,0, n-1, m-1);
        System.out.println("Jump-2 ans");
        System.out.println(ans1);
        


    }

    // sr - source row
    // sc - source column
    // dr - destination row
    // dc - destination column
        public static ArrayList<String> getMazePathsWithJumps(int sr, int sc, int dr, int dc) {
        if(sr == dr && sc == dc)
        {
            ArrayList<String> base = new ArrayList<String>();
            base.add("");
            return base;
        }
        ArrayList<String> myAns = new ArrayList<String>();
       for(int jump = 1; jump <= Math.max(dr,dc); jump++)
        {
            if(sc + jump <= dc)
            {
                ArrayList<String> recAns = getMazePathsWithJumps(sr , sc + jump, dr, dc);
                for(String ele : recAns)
                {
                    myAns.add("h"+jump+ele);
                }        
            }
            if(sr + jump <= dr)
            {
                ArrayList<String> vCall = getMazePathsWithJumps(sr + jump, sc, dr, dc);
                for(String ele : vCall)
                {
                    myAns.add("v" + jump + ele);
                }

            }
            if(sr + jump <= dr && sc + jump <= dc)
            {
                ArrayList<String> dCall = getMazePathsWithJumps(sr + jump, sc + jump , dr , dc);
                {
                    for(String ele : dCall)
                    {
                        myAns.add("d" + jump + ele);
                    }
                }
            }
            
        }
        return myAns;
        }
  public static ArrayList<String> getMazePathsWithJumps1(int sr, int sc, int dr, int dc) {
        if(sr == dr && sc == dc)
        {
            ArrayList<String> base = new ArrayList<String>();
            base.add("");
            return base;
        }
        ArrayList<String> myAns = new ArrayList<String>();
       for(int jump = 1; sc + jump <= dc; jump++)
        {
           ArrayList<String> recAns = getMazePathsWithJumps1(sr , sc + jump, dr, dc);
           for(String ele : recAns)
           {
               myAns.add("h"+jump+ele);
            }        
        }
       for(int jump = 1; sr + jump <= dr; jump++)
        {
           ArrayList<String> recAns = getMazePathsWithJumps1(sr + jump , sc , dr, dc);
           for(String ele : recAns)
           {
               myAns.add("v"+jump+ele);
            }        
        }
       for(int jump = 1;  sr+jump <= dr && sc + jump <= dc; jump++)
        {
           ArrayList<String> recAns = getMazePathsWithJumps1(sr+jump , sc + jump, dr, dc);
           for(String ele : recAns)
           {
               myAns.add("d"+jump+ele);
            }        
        }
        return myAns;
    }

}