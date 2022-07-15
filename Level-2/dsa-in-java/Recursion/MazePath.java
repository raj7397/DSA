import java.util.Scanner;



public class MazePath {
    public static class mazePair{
        public String shortestPath;
        public int shortestPathLen;
        public mazePair(String shortestPath, int shortestPathLen)
        {
            this.shortestPath = shortestPath;
            this.shortestPathLen = shortestPathLen;
        }

    }

    public static boolean isSafe(int sr, int sc, int n,int m)
    {
       // int n = visited.length;
        //int m = visited[0].length;
        if(sr < 0 || sr >= n || sc < 0 || sc >= m)
            return false;

        return true;
    }
    public static int printAllPath(int sr, int sc, int dr, int dc,int [][] dir, String [] dirName, String psf)
    {
        if(sr == dr && sc == dc)
        {
            System.out.println(psf);
            return 1;
        }
        int count = 0;
        for(int i = 0; i < dirName.length;i++)
        {
            int x = sr + dir[i][0];
            int y = sc + dir[i][1];
            
            if(isSafe(x,y,dr + 1,dc + 1))
            {
               count = count +  printAllPath(x,y,dr,dc,dir,dirName, psf + dirName[i]);
            }
        }
        return count;
    }
    public static void mazePath()
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        int [][] dir = {{0,1},{1,0},{1,1}};
        String [] dirName = {"H","V","D"};
        System.out.println(printAllPath(0,0,n - 1, m -1,dir,dirName,""));

    }
    public static void mazePathWithJumps()
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        int [][] dir = {{0,1},{1,0},{1,1}};
        String [] dirName = {"H", "V","D"};
        System.out.println(printAllPathWithJumps(0,0,n - 1, m- 1, dir, dirName,""));
    }
    public static int printAllPathWithJumps(int sr, int sc, int dr, int dc, int [][]dir,String [] dirName,String psf)
    {
        if(sr == dr && sc == dc)
        {
            System.out.println(psf);
            return 1;
        }
        int ans = 0;
        for(int i = 0; i <dirName.length;i++)
        {
            for(int jump = 1; jump <= Math.max(dr, dc);jump++)
            {
                int x = sr + (dir[i][0] * jump);
                int y = sc +(dir[i][1] * jump);
                if(isSafe(x,y,dr+1, dc+ 1))
                {
                    ans += printAllPathWithJumps(x, y, dr, dc, dir, dirName, psf+dirName[i]+jump);
                }
            }
        }
        return ans;
    }
    public static void floodFill()
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        boolean [][] visited = new boolean[n][m];
        int [][] dir = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
        String [] dirName = {"A","B","C","D","E","F","G","H"};
        System.out.println(floodFillSolver(0,0,n -1, m - 1, dir, dirName,"",visited));
    }
    public static boolean isSafe(int r, int c, boolean [][] visited)
    {
        int n = visited.length;
        int m = visited[0].length;
        if(r < 0 || r >= n || c <0 || c >=m || visited[r][c])
            return false;
        return true;
    }
    public static int floodFillSolver(int sr, int sc, int dr, int dc, int [][] dir, String [] dirName, String psf, boolean [][] visited)
    {
        if(sr == dr && sc == dc)
        {
            System.out.println(psf);
            return 1;
        }
        visited[sr][sc] = true;
        int ans = 0;
        for(int i = 0; i < dirName.length;i++)
        {
            int r = sr + dir[i][0];
            int c = sc + dir[i][1];
            if(isSafe(r,c,visited))
            {
                ans += floodFillSolver(r, c, dr, dc, dir, dirName, psf+dirName[i], visited);
            }
        }
        visited[sr][sc] = false;
        return ans;
    }
   
   public static mazePair mazeWithShortestPathSolver(int sr, int sc, int dr, int dc, int [][] dir,String [] dirName, String psf)
   {
        if(sr == dr && sc == dc)
        {
            return (new mazePair(psf, psf.length()));
        }
        String sPath = "";
        int sLen = Integer.MAX_VALUE;
        for(int i = 0; i < dir.length; i++)
        {
            int r = sr + dir[i][0];
            int c = sc + dir[i][1];
            if(isSafe(r,c,dr + 1, dc + 1))
            {
                mazePair ra = mazeWithShortestPathSolver(r, c, dr, dc, dir, dirName, psf + dirName[i]);
                if(ra.shortestPathLen <= sLen)
                {
                    sLen = ra.shortestPathLen;
                    sPath = ra.shortestPath;
                  //  System.out.println("sPath: "+ sPath+" sLen: "+sLen);
                }
            }
        }
        return (new mazePair(sPath, sLen));
   }
   public static void floodFillWithJumps()
   {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        boolean [][] visited = new boolean[n][m];
        int [][] dir = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
        String [] dirName = {"A","B","C","D","E","F","G","H"};
        System.out.println(floodFillWithJumpSolver(0,0,n -1, m - 1, dir, dirName,"",visited));
   }
    public static int floodFillWithJumpSolver(int sr, int sc, int dr, int dc, int [][] dir,String [] dirName, String psf, boolean [][] visited)
    {
        if(sr == dr && sc == dc)
        {
            System.out.println(psf);
            return 1;
        }
        visited[sr][sc] = true;
        int ans = 0;
        for(int i = 0; i <dir.length;i++)
        {
            for(int jump = 1; jump <= Math.max(dr, dc);jump++)
            {
                int x = sr + (dir[i][0] * jump);
                int y = sc +(dir[i][1] * jump);
                if(isSafe(x,y, visited))
                {
                    ans+= floodFillWithJumpSolver(x, y, dr, dc, dir, dirName, psf + dirName[i]+jump, visited);
                   // ans += printAllPathWithJumps(x, y, dr, dc, dir, dirName, psf+dirName[i]+jump);
                }
            }
        }
        visited[sr][sc] = false;
        return ans;
    }
    public static void mazeWithShortestPath()
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        int [][] dir = {{0,1},{1,0},{1,1}};
        String [] dirName = {"H","V","D"};
        mazePair mp = mazeWithShortestPathSolver(0,0,n -1, m - 1,dir,dirName,"");
        System.out.println(mp.shortestPath+ " "+mp.shortestPathLen);


    }
    public static void main(String[] args) {
    // mazePath();
   // mazePathWithJumps();
    //floodFill();
    floodFillWithJumps();
   // mazeWithShortestPath();
    }


    
}
