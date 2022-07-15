#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
int largest_common_span_on2(vector<int> &arr1, vector<int>&arr2);
int largest_common_span_on(vector<int> &arr1, vector<int>&arr2);
int main(int argc, char **argv)
{
    int n;
    cin>>n;
    vector<int>arr1(n);
    vector<int>arr2(n);
    for(int i = 0; i < n;i++)
    {
        cin>>arr1[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin>>arr2[i];
    }
 //   int ans1 = largest_common_span_on2(arr1,arr2);
   // cout<<ans1<<endl;
    int ans2 = largest_common_span_on(arr1, arr2);
    cout<<ans2<<endl;
}
int largest_common_span_on2(vector<int>&arr1, vector<int>&arr2)
{
    int res = 0;
    for(int i = 0; i < arr1.size(); i++)
    {
        int sum1 = 0;
        int sum2 = 0;
        for(int j = i; j < arr1.size(); j++)
        {
            sum1= sum1 + arr1[j];
            sum2 = sum2 + arr2[j];
            if(sum1 == sum2)
            {
                res = max(res, j - i + 1);
            }
        }
    }
    return res;
}
int largest_common_span_on(vector<int> & arr1, vector<int>&arr2)
{
    int n = arr1.size();
    vector<int>temp(n);
    for(int i = 0; i < temp.size(); i++)
    {
        temp[i] = arr1[i] - arr2[i];
    }
    int preSum = 0;
    int res = 0;
    unordered_map<int,int>mp;
    for(int i = 0; i < n; i++)
    {
        preSum = preSum + temp[i];
        if(preSum == 0)
        {
            res = max(res, i + 1);
        //    mp[preSum] = i;
        }
        if(mp.find(preSum - 0) != mp.end())
        {
            res = max(res, i - mp[preSum]);
        }
        if(mp.find(preSum) == mp.end())
        {
            mp[preSum] = i;
        }
    }
    return res;
}