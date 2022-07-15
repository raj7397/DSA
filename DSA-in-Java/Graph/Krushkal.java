package Graph;

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
   public static void krushkalAlgo(ArrayList<Edge> [] graph)
   {
       int V = graph.length;
       int [] parent = new int [V];
       int [] rank = new int[V];
       for(int i = 0;i < parent.length; i++)
       {
            parent[i] = i;
            rank[i] = 0;
       }
       PriorityQueue<Edge> pq = new PriorityQueue<>((a,b)-> {return a.wt - b.wt;});
       for(int i = 0; i < graph.length;i++)
       {
           for(int j = 0; j < graph[i].size();j++)
           {
                Edge e = graph[i].get(j);
                pq.add(e);
           }
       }
       int count = 0;
       HashSet<String>hs = new HashSet<>();
       while(pq.size() > 0)
       {
           Edge remEdge = pq.peek();
           pq.remove();
           //System.out.println("Removed: "+remEdge.src+"-->"+ remEdge.nbr+"@"+remEdge.wt);
           int u = remEdge.src;
           int v = remEdge.nbr;
           int uLeader = find(u,parent);
           int vLeader = find(v,parent);
           String temp = "";
           temp+=u+v;
          // System.out.println("uLeader: "+uLeader+" vLeader: "+vLeader);
           if(uLeader != vLeader)
           {
                System.out.println(remEdge.src+"-->"+ remEdge.nbr+"@"+remEdge.wt);
                
                hs.add(temp);
               unionByRank(uLeader,vLeader,parent,rank);
           }
           else{
               if(hs.contains(temp) == false)
                    count++;
               //System.out.println("uLeader: "+uLeader+" vLeader: "+vLeader);
                  // count++;
           }
       }
       System.out.println("Cycle count: "+count);
   }
   public static void unionByRank(int s1, int s2, int [] parent,int [] rank)
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
           parent[s2] = s1;
           rank[s1]++;
       }
   } 
   public static int find(int x, int []parent)
   {
       if(parent[x] == x)
            return x;
        int pox = parent[x];
        int ra = find(pox,parent);
        parent[x] = ra;
        return ra;
   }
   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      int vtces = Integer.parseInt(br.readLine());
      ArrayList<Edge>[] graph =  new ArrayList[vtces];
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
