#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class myComp{
    public:
    bool operator() (vector<int> a, vector<int>b)
    {
        if(a[1] > b[1])
            return true;
        return false;
    }
};
class myComp4{
    public:
        bool operator()(vector<int>&a, vector<int>&b)
        {
            if(a[1] > b[1])
                return true;
            return false;
        }
};
void schedule_job(vector<vector<int>>&arr);
void schedule_job2(vector<vector<int>>&arr);
int main(int argc, char **argv)
{
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(2,0));
    for(int i = 0; i < n;i++)
    {
        cin>>arr[i][0];
        cin>>arr[i][1];
    }
    //schedule_job(arr);
    cout<<"Schedule job-2"<<endl;
    schedule_job2(arr);
}
void schedule_job(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(),myComp());
    vector<bool>visited(n,false);
    vector<int>res(n, -1);
    for(int i = 0; i < n; i++)
    {
        for(int j = min(n, arr[i][0])- 1; j >=0; j--)
        {
            if(visited[j] == false)
            {
                visited[j] = true;
                res[j] = i;
                break;
            }
        }
    }
    cout<<"printing job sequence: "<<endl;
    for(int i = 0; i < n;i++)
    {
        if(res[i] != -1)
        {
            int idx = res[i];
            cout<<"slot: "<<i<<" deadline: "<<arr[idx][0]<<" profit: "<<arr[idx][1]<<endl;

        }
    }
}
void schedule_job2(vector<vector<int>>&arr)
{
    sort(arr.begin(), arr.end(), myComp4());
    int n = arr.size();
    vector<int>visited(n, false);
    int res = 0;
    
    for(int i = 0; i < arr.size();i++)
    {
        for(int j = min(arr[i][0], n) - 1; j >= 0; j--)
        {
            if(!visited[j])
            {
                visited[j] = true;
                res +=arr[i][1];
                break;
            }
        }
    }
    cout<<"max profit: "<<res<<endl;
 //   return res;
}