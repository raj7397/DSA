#include <bits/stdc++.h>
 
using namespace std;
 class myComp{
     public:
     bool operator()(pair<int,int> a, pair<int,int> b)
     {
         if(a.second > b.second)
            return true;
        return false;
     }
 };
// Function to find out minimum valued node
// among the nodes which are not yet included in MST
int minnode(int n, int keyval[], bool mstset[]) {
  int mini = numeric_limits<int>::max();
  int mini_index;
 
  // Loop through all the values of the nodes
  // which are not yet included in MST and find
  // the minimum valued one.
  for (int i = 0; i < n; i++) {
    if (mstset[i] == false && keyval[i] < mini) {
      mini = keyval[i], mini_index = i;
    }
  }
  return mini_index;
}
 
// Function to find out the MST and
// the cost of the MST.
void findcost(int n, vector<vector<int>> city) {
 vector<bool>visited(n,false);
 priority_queue<pair<int,int>,vector<pair<int,int>>,myComp> pq;
 pq.push(make_pair(0,city[0][0]));
 int cost = 0;
 while(pq.size() > 0)
 {
     auto rp = pq.top();
     pq.pop();

     int u = rp.first;
     int c = rp.second;
     if(visited[u] == true)
        continue;
    visited[u] = true;
    cost+=c;
    for(int i = 0; i < city[u].size();i++)
    {
        if(city[u][i] != 0 && visited[i] == false)
        {
            pq.push(make_pair(i,city[u][i]));
        }
    }
 }
 cout<<"cost: "<<cost<<endl;
  
 
}
 
// Utility Program:
int main() {
 
  // Input 1
  int n1 = 5;
  vector<vector<int>> city1 = {{0, 1, 2, 3, 4},
                               {1, 0, 5, 0, 7},
                               {2, 5, 0, 6, 0},
                               {3, 0, 6, 0, 0},
                               {4, 7, 0, 0, 0}};
  findcost(n1, city1);
 
  // Input 2
  int n2 = 6;
  vector<vector<int>> city2 = {{0, 1, 1, 100, 0, 0},
                               {1, 0, 1, 0, 0, 0},
                               {1, 1, 0, 0, 0, 0},  
                               {100, 0, 0, 0, 2, 2},
                               {0, 0, 0, 2, 0, 2}, 
                               {0, 0, 0, 2, 2, 0}};
  findcost(n2, city2);
 
  return 0;
}