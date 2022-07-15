#include <iostream>
#include <vector>

using namespace std;
int find(int x, vector<int>&parent)
{
    if(parent[x] == x)
        return x;
    int pox = parent[x];
    int ra = find(pox,parent);
    parent[x] = ra;
    return ra;
}
void unionByRank(int s1,int s2, vector<int>&parent,vector<int>&rank)
{
    if(rank[s1] > rank[s2])
    {
        parent[s2] = s1;
    }
    else if(rank[s2] > rank[s1])
    {
        parent[s1] = s2;
    }
    else{
        parent[s2] = s1;
        rank[s1]++;
    }
}

void solve(vector<int>&arr1,vector<int>&arr2)
{
    int m = arr1.size();
    vector<int>parent(m+1);
    vector<int>rank(m+1);
    for(int i =0; i < m+1; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    for(int i = 0; i < m;i++)
    {
        int u = arr1[i];
        int v = arr2[i];
        int uLeader = find(u,parent);
        int vLeader = find(v,parent);
        if(uLeader != vLeader)
        {
            unionByRank(uLeader,vLeader,parent,rank);
        }
        
    }
    int count = 0;
    for(int i = 1;i < m+1;i++)
    {
        if(parent[i] == i)
            count++;
    }
    int ans = 1;
    int MOD = 1000000007;
    for(int i = 1; i<= count;i++)
    {
        ans = ((ans%MOD)*(2 % MOD))%MOD;
    }
    cout<<ans<<endl;
}

int main()
{
    int n,m;
    cin>>n;
    while(n-- > 0)
    {
        cin>>m;
        vector<int>arr1(m);
        vector<int>arr2(m);
        for(int i = 0;i < m;i++)
        {
            cin>>arr1[i];
        }
        for(int i = 0; i < m; i++)
        {
            cin>>arr2[i];
        }
        solve(arr1,arr2);
        
    }    
}


