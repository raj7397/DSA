#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class myComp{
    public:
      bool operator()(vector<int>a, vector<int>b)
      {
          if(a[1] < b[1])
            return true;
         return false;
      }
};
class myComp3{
    public:
        bool operator()(vector<int>& a, vector<int>&b)
        {
            if(a[1] < b[1])
                return true;
            return false;
        }
};
int max_task(vector<vector<int>>&arr);
int max_activities(vector<vector<int>>&);
int main(int argc, char **argv)
{
    int n; 
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(2));
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i][0];
        cin>>arr[i][1];
    }
    int ans = max_task(arr);
    cout<<ans<<endl;
    ans = max_activities(arr);
    cout<<"ans: "<<ans<<endl;
}
int max_activities(vector<vector<int>>&arr)
{
    sort(arr.begin(), arr.end(), myComp3());
    int idx = 0, ans = 1;
    for(int i = 1; i < arr.size();i++)
    {
        if(arr[i][0] >= arr[idx][1])
        {
            idx = i;
            ans++;
        }
    }
    return ans;
}

int max_task(vector<vector<int>>&arr)
{
    int n = arr.size();
    sort(arr.begin(),arr.end(), myComp());
    int pos = 0;
    int res = 1;
    for(int i =1; i <n; i++)
    {
        if(arr[i][0] >= arr[pos][1])
        {
            res++;
            pos = i;
        }
    }
    return res;
}