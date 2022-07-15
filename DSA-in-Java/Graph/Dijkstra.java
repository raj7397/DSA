import java.io.*;
import java.util.*;

public class Dijkstra {
   static class pair{
      int u;
      int cost;
      pair(int u, int cost)
      {
         this.u = u;
         this.cost = cost;
      }
   }
   static class Edge {
      int src;
      int nbr;
      int wt;

      Edge(int src, int nbr, int wt) {
         this.src = src;
         this.nbr = nbr;
         this.wt = wt;
      }
   }

   public static int[] dijkstraAlgo(ArrayList<Edge> [] graph,int src)
   {
      PriorityQueue<pair> pq = new PriorityQueue<>((a,b)->{
         return a.cost - b.cost;
      });
      int N = graph.length;
      boolean [] visited = new boolean[N];
      int [] cost = new int[N];
     // cost[0] = 0;
      pq.add(new pair(src,0));

      while(pq.size() > 0)
      {
         //System.out.println("Rajkalash");
         pair rem = pq.peek();
         pq.remove();
         int u = rem.u;
         int c = rem.cost;
         //System.out.println("cost: "+ c);
         if(visited[u] == false)
         {
            visited[u] = true;
            cost[u] = c;
         }
         for(int i = 0; i < graph[u].size(); i++)
         {
            Edge edge = graph[u].get(i);
            int v = edge.nbr;
            int wt = edge.wt;
            //System.out.println("wt: "+wt);
            if(visited[v] == false)
            {
               pq.add(new pair(v, c + wt));
            }
         }
         //System.out.println("pq size: "+pq.size());
      
      }

      return cost;
   }
   public static int[] dijkstraAlgoWithOneArray(ArrayList<Edge> [] graph, int src)
   {
      PriorityQueue<pair> pq = new PriorityQueue<>((a,b)->{
         return a.cost - b.cost;
      });
      int N = graph.length;
      int [] path = new int[N];
      Arrays.fill(path, Integer.MAX_VALUE);
      pq.add(new pair(src, 0));
      while(pq.size() > 0)
      {
         pair rem = pq.peek();
         pq.remove();
         int u = rem.u;
         int cst = rem.cost;
         if(path[u] == Integer.MAX_VALUE)
         {
            path[u] = cst;

         }
         for(int i = 0; i < graph[u].size(); i++)
         {
            Edge edge = graph[u].get(i);
            int v = edge.nbr;
            int wt = edge.wt;
            if(path[v] == Integer.MAX_VALUE)
            {
               pq.add(new pair(v, cst + wt));
            }
         }
      }
      return path;
   }
   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int vtces = Integer.parseInt(br.readLine());
      ArrayList<Edge>[] graph = new ArrayList[vtces];
      for (int i = 0; i < vtces; i++) {
         graph[i] = new ArrayList<>();
      }

      int edges = Integer.parseInt(br.readLine());
      for (int i = 0; i < edges; i++) {
         String[] parts = br.readLine().split(" ");
         int v1 = Integer.parseInt(parts[0]);
         int v2 = Integer.parseInt(parts[1]);
         int wt = Integer.parseInt(parts[2]);
         graph[v1].add(new Edge(v1, v2, wt));
         graph[v2].add(new Edge(v2, v1, wt));
      }

      int src = Integer.parseInt(br.readLine());
      int [] path = dijkstraAlgoWithOneArray(graph,src);
      //int [] path = dijkstraAlgo(graph, src);
      for(int x: path)
      {
          System.out.print(x + " ");
      }
      System.out.println();
      // write your code here
      
   }
}