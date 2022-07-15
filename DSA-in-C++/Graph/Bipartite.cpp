#include <iostream>
#include <vector>
#include <queue>
#include<string>
using namespace std;

class Edge
{
public:
  int src = 0;
  int nbr = 0;

  Edge(int src, int nbr)
  {
    this->src = src;
    this->nbr = nbr;
  }
};
class qPair{
    public:
    int v;
    int col;
    qPair(int v, int col)
    {
        this->v = v;
        this->col = col;
    }
};
bool isBipartite(vector<vector<Edge>> graph,vector<int>&visCol,int src)
{
    cout<<"src: "<<src<<endl;
    //int n = graph.size();
//    vector<int>visCol(n, -1);
    queue<qPair> q;
    q.push(qPair(src,0));
    while(q.size() > 0)
    {
        qPair rem = q.front();
        q.pop();
        int u = rem.v;
        int cl = rem.col;
        if(visCol[u] == -1)
        {
            visCol[u] = cl;
        }
        if(visCol[u] != cl)
            return false;
        for(int i = 0; i < graph[u].size();i++)
        {
            Edge edge = graph[u][i];
            int v = edge.nbr;
            if(visCol[v] == -1)
            {
                q.push(qPair(v, 1 - cl));
            }
        }
    }
    return true;
}
bool isBipartiteSolver(vector<vector<Edge>> graph)
{
    int n = graph.size();
    vector<int>visCol(n,-1);
    for(int i = 0; i < n; i++)
    {
        if(visCol[i] == -1)
        {
            if(isBipartite(graph,visCol,i) == false)
            {
                cout<<"u: "<<i<<" false"<<endl;
                return false;
            }
        }
                //return false;
    }
    return true;
}
int main() {
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());


  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w;
    cin >> u >> v >> w;

    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));

  }
   bool ans = isBipartiteSolver(graph);
   if(ans == true)
        cout<<"true"<<endl;
   else
        cout<<"false"<<endl;
  // write your code here
  return 0;
}