#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int size_of_subarray_with_max_sum(vector<int>&arr);
int main(int argc, char ** argv)
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int ans = size_of_subarray_with_max_sum(arr);
    cout<<"ans: "<<ans<<endl;
}
int size_of_subarray_with_max_sum(vector<int>&arr)
{
    int n = arr.size();
    if(n==1)
        return 1;
    int prevSum = arr[0];
    int currSum = 0;
    int start = 0;
    int end = 0;
    int sz = INT_MIN;
    int ans = arr[0];
    for(int i = 1 ; i < n; i++)
    {
        if(prevSum + arr[i] > arr[i])
        {
            prevSum+= arr[i];
            end++;
        }
        else{
            prevSum = arr[i];
            start = i;
            end = i;
        }
        cout<<"preSum: "<<prevSum<<" ans: "<<ans<<endl;
        if(prevSum > ans)
        {
            ans = prevSum;
            sz = max(sz , end - start +1);
        }
    }
    cout<<"size: "<<sz<<endl;
    return sz;

}