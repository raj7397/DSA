import java.util.*;
import java.io.*;

public class RecursionArrayListQns
{
    public static String [] codes = {".;","abc","def" , "ghi","jkl","mno", "pqrs","tu","vwx","yz"};
    static int [][] dir = {{0, 1},{1, 0},{1, 1}};
    static String [] dirN = {"h", "v","d"};
    public static void main(String [] args)
    {
        sovleEncoding();
      //  solveMazePathWithJump3();
      //  solveMazePathWithJumps();
        //solveMazePathWithJumpsRightSol();
        //solveMazePath();
    //        solveGetKpc();
        //solveGetStairPath();
        // solveGetSubSequence();


    }
    public static void sovleEncoding()
    {
        Scanner scn = new Scanner(System.in);
        String str = scn.next();
        printEncoding(str , "");
    }
    public static void printEncoding(String str, String ans)
    {
        if(str.length() == 0)
        {
            System.out.println(ans);
            return;
        }
        if(str.charAt(0) == '0')
        {
            return;
        }
        char ch1 = str.charAt(0);
        int d1 = ch1 - '0';
        String ros = str.substring(1);
        printEncoding(ros,ans + (char)(d1 + 'a' -1));
        if(str.length() >= 2)
        {
            char ch2 = str.charAt(1);
            int d2 = ch2 - '0';
            int num = d1*10+d2;
            if(num <= 26)
            {
                String ros1 = str.substring(2);
                printEncoding(ros1, ans + (char)('a' + num -1));
            }
        }
    }
    public static void solveMazePathWithJump3()
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();

        printMazePaths3(0,0,n-1,m-1, "");


    }
    public static void printMazePaths3(int sr, int sc, int dr, int dc, String psf) {
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
                    printMazePaths3(r, c, dr, dc, psf + dirN[d] + j);
                }
            }
        }
        
    }


    public static void solveMazePathWithJumpsRightSol()
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        ArrayList<String> ans = getMazePathsWithJumps1(0,0,n-1,m-1);
        System.out.println(ans);
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
    //Below approach is wrong for given questions

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
    public static void solveMazePathWithJumps()
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        ArrayList<String> ans = getMazePathsWithJumps(0 ,0 ,n-1 , m-1);
        System.out.println(ans);
    }
    public static void solveMazePath()
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        ArrayList<String> ans = getMazePath(0, 0, n-1, m-1);
        System.out.println(ans);

    }
    public static ArrayList<String> getMazePath(int sr, int sc, int dr, int dc)
    {
        if(sr == dr && sc == dc)
        {
            ArrayList<String> base = new ArrayList<>();
            base.add("");
            return base;
        }
        ArrayList<String> myAns = new ArrayList<>();
        if(sc + 1 <= dc)
        {
            ArrayList<String> recAns = getMazePath(sr , sc+1, dr, dc);
            for(String ele : recAns)
            {
                myAns.add("v" + ele);
            }
        }
        if(sr + 1 <= dr)
        {
            ArrayList<String> recAns = getMazePath(sr + 1, sc, dr, dc);
            for(String ele : recAns)
            {
                myAns.add("h" + ele);
            }
        }
        return myAns;
    }
    public static void solveGetKpc()
    {
        Scanner scn = new Scanner(System.in);
        String str = scn.next();
        ArrayList<String> ans = getKpc(str);
        System.out.println(ans);
    }
    public static ArrayList<String> getKpc(String str)
    {
        if(str.length() == 0)
        {
            ArrayList<String> base = new ArrayList<>();
            base.add("");
            return base;
        }
        char ch = str.charAt(0);
        String ros = str.substring(1);
        ArrayList<String> recAns = getKpc(ros);
        int h = ch - '0';
        String temp = codes[h];
        ArrayList<String> ans = new ArrayList<>();
        for(int i = 0; i < temp.length(); i++)
        {
            for(String ele: recAns)
            {
                ans.add(temp.charAt(i) + ele);
            }
        }
        return ans;
    }
    public static void solveGetStairPath()
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        ArrayList<String> ans = getStairPath(n);
        System.out.println(ans);
    }
    public static ArrayList<String> getStairPath(int n)
    {
        if(n == 0)
        {
            ArrayList<String> base = new ArrayList<>();
            base.add("");
            return base;
        }
        ArrayList<String> ans = new ArrayList<>();
        for(int i = 1; i <= 3; i++)
        {
            if(n-i >= 0)
            {
                ArrayList<String> recAns = getStairPath(n-i);
                for(String ele : recAns)
                {
                    ans.add(i + ele);
                }
            }
        }
        return ans;

 /*       if(n == 0)
        {
            ArrayList<String> base = new ArrayList<>();
            base.add("");
            return base;
        }
        ArrayList<String> ans = new ArrayList<>(); 
        if(n-1 >= 0)
        {
            ArrayList<String> ans1 = getStairPath(n-1);
            for(String ele : ans1)
            {
                ans.add(1 + ele);
            }
        }
        if(n-2 >= 0 )
        {
            ArrayList<String> ans2 = getStairPath(n-2);
            for(String ele : ans2)
            {
                ans.add(2 + ele);
            }
        }
        if(n-3 >= 0)
        {
            ArrayList<String> ans3 = getStairPath(n-3);
            for(String ele : ans3)
            {
                ans.add(3 + ele);
            }
        }
        return ans;*/
    }
    public static void solveGetSubSequence()
    {
     Scanner scn = new Scanner(System.in);
     String str = scn.next();
     ArrayList<String> ans = getSubSequence(str);
     System.out.println(ans);


    }
    public static ArrayList<String> getSubSequence(String str)
    {
        if(str.length()==0)
        {
            ArrayList<String> base = new ArrayList<>();
            base.add("");
            return base;
        }
        char ch = str.charAt(0);
        String ros = str.substring(1);
        ArrayList<String> recAns = getSubSequence(ros);
        ArrayList<String> myAns = new ArrayList<>();
        for(String ele : recAns)
        {
            myAns.add(ele);
        }
        for(String ele : recAns)
        {
            myAns.add(ch + ele);
        }
        return myAns;

    }
}