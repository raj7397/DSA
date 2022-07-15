#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int maxCircularSubArraySum(vector<int> &arr);
int main(int argc, char **argv)
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int ans = maxCircularSubArraySum(arr);
    cout<<"ans: "<<ans<<endl;
}
int maxCircularSubArraySum(vector<int> &arr)
{
    int n = arr.size();
    int ans = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int sum = arr[i];
        int curr_max = arr[i];
        for(int j = 1; j < n; j++)
        {
            int idx = (i + j)%n;
            sum = sum + arr[idx];
            curr_max = max(curr_max, sum);

        }
        ans = max(ans, curr_max);
    }
    return ans;
}