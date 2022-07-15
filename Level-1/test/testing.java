public class testing{
    public static void main(String [] args)
    {
        boolean [][] visited = new boolean[3][3];
        System.out.println("Visited array: ");
        for(int i = 0; i < visited.length; i++)
        {
            for(int j = 0 ; j < visited[0].length; j++)
            {
                System.out.print(visited[i][j]+ " ");
            }
            System.out.println();
        }
       // System.out.println("testing java");
    }
}