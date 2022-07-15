#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class myComp1{
    public: 
      bool operator()(vector<int> &a, vector<int>&b)
      {
          double v1 = (double)a[1]/a[0];
          double v2 = (double)b[1]/b[0];
          if(v1 > v2)
            return true;
          //if(a[1] > b[1])
           // return true;
        return false;
      }
};
class myComp2{
    public:
    bool operator()(vector<int> &a, vector<int>&b)
    {
        double v1 = (double)a[1]/a[0];
        double v2 = (double)b[1]/b[0];
        if(v1 > v2)
            return true;
        return false;
    }
};
/*class myComp1{
    public:
    bool operator() (vector<int> a, vector<int>b)
    {
        if(a[1] > b[1])
            return true;
        return false;
    }
};*/
double max_profit2(vector<vector<int>>& arr, int total);

double max_profit(vector<vector<int>>&arr,int );
int main(int argc, char **argv)
{
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(2,0));
    for(int i =0; i < n; i++)
    {
        cin>>arr[i][0];
        cin>>arr[i][1];
    }
    int total;
    cin>>total;
    double ans = max_profit(arr, total);
    cout<<ans<<endl;
    ans = max_profit2(arr,total);
    cout<<"ans: "<<ans<<endl;
}
double max_profit2(vector<vector<int>>&arr, int total)
{
    double profit = 0;
    sort(arr.begin(),arr.end(),myComp2());
    for(int i = 0; i < arr.size();i++)
    {
        if(arr[i][0] <= total)
        {
            total -= arr[i][0];
            profit +=arr[i][1];
        }
        else{
            profit += (double)(arr[i][1] * total)/arr[i][0];
            break;
        }
    }
    return profit;
}
double max_profit(vector<vector<int>>&arr,int total)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(),  myComp1());
   /* cout<<"after sort: "<<endl;
    for(int i = 0; i <n ;i++)
    {
        cout<<"wt: "<<arr[i][0]<<" profit: "<<arr[i][1]<<endl;
    }*/
    double ans = 0.0;
    for(int i =0; i < n; i++)
    {
        if(arr[i][0] <= total)
        {
            total = total - arr[i][0];
            ans = ans + arr[i][1];
        }
        else{
                ans = ans + (double)(arr[i][1] *total)/arr[i][0];
                break;
        }
    }
    return ans;
}
