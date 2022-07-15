#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:

    class qPair{
      public:
        int u;
        int color;
        qPair(int u, int color)
        {
            this->u = u;
            this->color = color;
        }
    };
    bool isBipartite(vector<vector<int>>& graph) {
      //  queue<qPair>q;
        int n = graph.size();
        vector<int>visCol(n,-1);
        for(int i = 0; i < n ; i++)
        {
            if(visCol[i] == -1)
            {
                if(bfs(graph,i,visCol) == false)
                    return false;
            }
        }
        return true;
        
    }
    bool bfs(vector<vector<int>>&graph,int src,vector<int>&visCol)
    {
        cout<<"src: "<<src<<endl;
        queue<qPair>q;
        q.push(qPair(src,0));
        while(q.size() > 0)
        {
            qPair rem = q.front();
            q.pop();
            int u = rem.u;
            int col = rem.color;
            cout<<"u: "<<u<<" color: "<<col<<endl;
            if(visCol[u] == -1)
            {
                visCol[u] = col;
                cout<<"insdie -1 : "<<endl;
                cout<<"u: "<<u<<" color: "<<col<<endl;
            }
            if(visCol[u] != col)
            {
                cout<<"inside return: "<<endl;
                cout<<"visCol[u] "<<visCol[u]<<" col: "<<col<<endl;
                cout<<"u: "<<u<<" color: "<<col<<endl;
                return false;
            }
            for(int i = 0; i < graph[u].size();i++)
            {
                int v = graph[u][i];
                if(visCol[v] == -1)
                {
                    q.push(qPair(v,1 - col));
                }
                    
            }
        }
        return true;
        
    }
};
int main(int argc, char ** argv)
{
    int n,t;
    cin>>n;
    vector<vector<int>>graph;
    for(int i = 0; i < n; i++)
    {
        vector<int>temp;
        int m;
        cin>>m;
        for(int j = 0; j < m; j++)
        {
            cin>>t;
            temp.push_back(t);
        }
        graph.push_back(temp);
    }
    Solution s = Solution();
    bool ans = s.isBipartite(graph);
    cout<<"ans: "<<ans<<endl;
}