#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;
int minSwap(vector<int>&A,vector<int>&B)
{
    unordered_map<int,int>iPos;
    for(int i = 0; i < B.size();i++)
    {
        iPos[B[i]] = i;
    }
    vector<bool>visited(B.size(),false);
    int ans =0;
    for(int i = 0; i < B.size();i++)
    {
        if(visited[i] == true || iPos[A[i]] == i)
            continue;
        
        visited[i] = true;
        int j = i;
        int cSize = 0;
        do{
            j = iPos[A[j]];
            visited[j] = true;
            cSize++;
        }
        while(j != i);
        ans+=cSize-1;
    }
    return ans;
}
int main(int argc, char ** argv)
{
    int n;
    cin>>n;
    vector<int>A(n);
    vector<int>B(n);
    for(int i = 0; i < n;i++)
    {
        cin>>A[i];
    }
    for(int i = 0;  i < n;i++)
    {
        cin>>B[i];
    }
    int ans = minSwap(A,B);
    cout<<"ans: "<<ans<<endl;
}