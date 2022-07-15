#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

bool pathFound(vector<vector<int>>&graph,vector<int>&parent);
int findMaxFlow(int N,int M,vector<vector<int>> Edges)
{
        // code here
        cout<<"in maxflow"<<endl;
        vector<vector<int>>graph(N+1,vector<int>(N+1));
    
        for(int i = 0; i < Edges.size();i++)
        {
            int u = Edges[i][0];
            int v = Edges[i][1];
            int wt = Edges[i][2];
            graph[u][v]+=wt;
            graph[v][u]+=wt;
         //   cout<<"graph"<<endl;
        }
        vector<vector<int>>rgraph = graph;
        vector<int>parent(N+1);
        
        int maxflow = 0;
        while(pathFound(rgraph,parent) == true)
        {
            int flow = INT_MAX;
            int v = N;
            cout<<"v: "<<v<<endl;
            while(v != 1)
            {
                int u = parent[v];
                if(rgraph[u][v] < flow)
                    flow = rgraph[u][v];
                v = u;
            }
            v = N;
            while( v!= 1)
            {
                int u = parent[v];
                rgraph[u][v]-=flow;
                rgraph[v][u]+=flow;
                v = u;
            }
            maxflow+=flow;
        }
        return maxflow;
}
bool pathFound(vector<vector<int>>&graph,vector<int>&parent)
{
    int k = parent.size() - 1;
    cout<<"k: "<<k<<endl;
        cout<<"bfs: "<<endl;
        vector<int>visited(parent.size(),false);
        queue<int>q;
        q.push(1);
        while(q.size() > 0)
        {
            auto u = q.front();
            q.pop();
            cout<<"u: "<<u<<endl;
            if(visited[u] == true)
                continue;
            visited[u] = true;
            cout<<"parent.size()-1: "<<(parent.size() - 1)<<endl;
            if(u == parent.size() -1)
            {
                cout<<"in return: "<<endl;
                return true;
            }
              //  return true;
            for(int i = 1; i < graph.size();i++)
            {
                if(graph[u][i] > 0 && visited[i] == false)
                {
                    parent[i] = u;
                    q.push(i);
                }
                cout<<"i: "<<i<<endl;
            }
        }
        cout<<"Before returning false:"<<endl;
        return false;
}
int main(int argc, char ** argv)
{
    int N,M;
    cin>>N>>M;
    vector<vector<int>>Edges(M,vector<int>(3));
    for(int i = 0; i < M;i++)
    {
        cin>>Edges[i][0];
        cin>>Edges[i][1];
        cin>>Edges[i][2];
    }
    cout<<"ans: "<<findMaxFlow(N,M,Edges)<<endl;
}




