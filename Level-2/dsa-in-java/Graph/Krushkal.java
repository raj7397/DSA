import java.io.*;
import java.util.*;


public class Krushkal {
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
   static int [] parent;
   static int [] rank;
   public static void krushkalAlgo(ArrayList<Edge> [] graph)
   {
       PriorityQueue<Edge> pq = new PriorityQueue<>((a,b)->{return a.wt - b.wt;});
       for(int v = 0; v < graph.length;v++)
       {
           for(int i = 0; i < graph[v].size();i++)
           {
               Edge e = graph[v].get(i);
               pq.add(e);
           }
       }
       parent = new int[graph.length];
       rank = new int[graph.length];
       for(int i = 0; i < graph.length;i++)
       {
           parent[i] = i;
       }
       while(pq.size() > 0)
       {
           Edge e = pq.peek();
           pq.remove();
           int u = e.src;
           int v = e.nbr;
           int uLeader = find(u);
           int vLeader = find(v);
           if(uLeader != vLeader)
           {
            System.out.println(u+"-->"+v+"@"+e.wt);
            union(uLeader,vLeader);
           }
       }

   }
   public static void union(int s1, int s2)
   {
       if(rank[s1] > rank[s2])
       {
           parent[s2] = s1;
       }
       else if(rank[s1] < rank[s2])
       {
           parent[s1] = s2;
       }
       else{
           parent[s1] = s2;
           rank[s2]++;
       }
   }
   public static int find(int x)
   {
       if(parent [x] == x)
            return x;
        int pox = parent[x];
        int ra = find(pox);
        parent[x] = ra;
        return ra;
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
      krushkalAlgo(graph);
      // write your code here
   }

}