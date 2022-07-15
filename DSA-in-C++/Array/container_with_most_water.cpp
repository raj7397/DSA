#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &A) {
    int n = A.size();
    int lmax[n];
    int rmax[n];
    lmax[0] = 0;
    rmax[n - 1] = n - 1;
    for(int i = 1 ; i < n ; i++)
    {
        if(A[i] > A[lmax[i - 1]])
        {
            lmax[i] = i;
        }
        else{
            lmax[i] = lmax[i - 1];
        }
    }
    cout<<"print"<<endl;
    for(int j = 0; j < n; j++)
    {
        cout<<lmax[j]<<" ";
    }
    cout<<"done"<<endl;
    for(int i = n -2; i >= 0; i--)
    {
        if(A[i] > A[rmax[i + 1]])
        {
            rmax[i] = i;
        }
        else{
            rmax[i] = rmax[i + 1];
        }
    }
    int ans = 0;
    cout<<"lmax: "<<endl;
    for(int i= 0; i <n; i++)
    {
        //cout<<"hi: "<<endl;
        cout<<lmax[i]<<" ";
    }
    cout<<"\rmax: "<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<rmax[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < n; i++)
    {
        int minVal = min(A[lmax[i]], A[rmax[i]]);
        ans = max(ans, minVal * (rmax[i] - lmax[i]));
    }
    return ans;
}
int main(int argc, char **argv)
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int ans = maxArea(arr);
    cout<<"ans: "<<ans<<endl;
}