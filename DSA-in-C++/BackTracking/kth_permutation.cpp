#include <iostream>
#include <vector>
#include <climits>
using namespace std;
string kthPermmutationHelper(int k, vector<int>&nums);
string kthPermmutation(int n, int k);
int fact(int n);
int main(int argc, char ** argv)
{
    int n,k;
    cin>>n>>k;
    vector<int> factTab(n)
    string ans = kthPermmutation(n,k);
    cout<<"ans: "<<ans<<endl;
}
string kthPermmutation(int n, int k)
{
    vector<int>nums;
    for(int i = 1; i <= n; i++)
    {
        nums.push_back(i);
    }
    string ans = kthPermmutationHelper(k,nums);
    return ans;
}
string kthPermmutationHelper(int k, vector<int>&nums)
{
    int n = nums.size();
    if(n == 1)
    {
        string baseAns = "";
        baseAns = baseAns + to_string(nums[0]);
        return baseAns;
    }
    if(k > fact(n) || k < 0)
        return "";
    int blockSize = fact(n - 1);
    int index = k/blockSize;
    if(k % blockSize == 0)
        index= index - 1;
    k = k - index * blockSize;
    string temp = to_string(nums[index]);
    nums.erase(nums.begin() + index);
    //string recAns = temp;
    string recAns = kthPermmutationHelper(k, nums);
    return temp + recAns;

}
int fact(int n)
{
    if(n > 12)
        return INT_MAX;
    int f = 1;
    for(int i = 2; i <= n; i++)
    {
        f = f*i;
    }
    return f;
}
