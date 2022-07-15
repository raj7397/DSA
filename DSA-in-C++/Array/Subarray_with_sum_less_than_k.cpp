#include <iostream>
#include <vector>

using namespace std;
int Solution2(vector<int>&arr,int k)
{
    int sum =0;
    int n = arr.size();
    int i  = 0,start = 0;
    int ans = 0;
    while(i < n)
    {
        sum = sum + arr[i];
       // sum+=arr[i];
        while(sum > k)
        {
            sum = sum -arr[start];
            //sum-=arr[start];
            start++;
        }
        if(start < n)
        {
            ans = ans + (i - start + 1);
          //  cout<<"ans: "<<ans<<" i: "<<i<<" start: "<<start<<endl;
            //ans+=i - start + 1;
        }
        i++;
    }
    return ans;
}
int main(int argc, char ** argv)
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    int ans = Solution2(arr,k);
    cout<<"ans: "<<ans<<endl;
}