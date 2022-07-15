#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int no_of_triangle(vector<int>&arr);
int main(int argc, char **argv)
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int ans = no_of_triangle(arr);
    cout<<"ans: "<<ans<<endl;
}
int no_of_triangle(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int ans = 0;
    for(int k = arr.size() - 1; k >= 2; k--)
    {
        int i = 0; 
        int j = k - 1;
        while(i < j)
        {
            if(arr[i] + arr[j] > arr[k])
            {
                ans += j - i;
                j--;
            }
            else{
                i++;
            }
        }
    }
    return ans;
}