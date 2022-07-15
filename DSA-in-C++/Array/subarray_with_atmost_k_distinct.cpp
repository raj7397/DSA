#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace  std;

int sub_array_atmost_k_dist(vector<int> &A, int B)
{

    int start = 0, end = 0, n = A.size(), count = 0;
    unordered_map<int,int>mp;
    while(end < n)
    {
        mp[A[end]]++;
        while(mp.size() > B)
        {
            mp[A[start]]--;
            if(mp[A[start]] == 0)
            {
                mp.erase(A[start]);
            }
            start++;
        }
        count = count + end -start + 1;
        end++;
    }
    return count;
}
int efficient_sol(vector<int> &A, int B)
{
    return (sub_array_atmost_k_dist(A, B) - sub_array_atmost_k_dist(A, B -1));
}

int main(int argc, char **argv)
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i =0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int ans = efficient_sol(arr, k);
    cout<<"ans: "<<ans<<endl;
}