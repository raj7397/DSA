#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void solve_print_subset();

int main()
{
    solve_print_subset();
}
void print_subset(vector<int>&arr,int idx, vector<vector<int>>&ans,vector<int>asf);
void solve_print_subset()
{
    int n;
    cin>>n;
    vector<int>arr;
    int val;
    for(int i = 0; i < n; i++)
    {
        cin>>val;
        arr.push_back(val);
    }
    vector<vector<int>>res;
    vector<int> asf;
    print_subset(arr, 0,res,asf);
    sort(res.begin(),res.end());
    for(int i = 0; i < res.size();i++)
    {
        for(auto x: res[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
void print_subset(vector<int>&arr,int idx, vector<vector<int>>& ans,vector<int> asf)
{
    if(idx >= arr.size())
    {
        ans.push_back(asf);
        return ;
    }
    print_subset(arr, idx + 1, ans, asf);
    asf.push_back(arr[idx]);
    print_subset(arr,idx + 1, ans, asf);
}