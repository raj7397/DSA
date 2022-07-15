#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> generate_permutation_sum(vector<int> &arr, int sum);
void solve_permutation(vector<int> &arr, int sum, vector<vector<int>> &ans,vector<int> temp);
int main()
{
  /*  vector<int> t; 
    t.push_back(19);
    t.push_back(38);
    for(int i = 0; i< t.size(); i++)
    {
        cout<<t[i]<<" ";
    }
    cout<<"\nafter pop_back()"<<endl;
    t.pop_back();
    for(int i = 0; i< t.size(); i++)
    {
        cout<<t[i]<<" ";
    }*/

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    vector<vector<int>> ans = generate_permutation_sum(arr, sum);
    cout<<"Ans: "<<endl;
    for(int i =0; i < ans.size(); i++)
    {
        for(int j = 0 ; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
void solve_permutation(vector<int> &arr, int sum, vector<vector<int>> &ans,vector<int> temp)
{
    if(sum == 0)
    {
        cout<<"inbase"<<endl;
        for(int i = 0; i < temp.size(); i++)
            cout<<temp[i]<<" ";
        cout<<"\n-----------------------------"<<endl;
        ans.push_back(temp);
        return;
    }
    for(int i =0; i < arr.size();i++)
    {
        if(sum - arr[i] >= 0)
        {
            temp.push_back(arr[i]);
            solve_permutation(arr,sum - arr[i], ans, temp);
            temp.pop_back();
        }
    }
}
vector<vector<int>> generate_permutation_sum(vector<int> &arr, int sum)
{
    vector<vector<int>> ans;
    vector<int>temp;
    solve_permutation(arr,sum,ans,temp);
    return ans;
}