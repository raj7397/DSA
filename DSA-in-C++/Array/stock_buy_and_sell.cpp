#include <iostream>
#include <vector>

using namespace std;
int bestPrice(vector<int>&arr,int start, int end);
int bestPriceEfficient(vector<int>&arr);

int main(int argc, char ** argv)
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int ans = bestPrice(arr,0,n - 1);
    cout<<"ans: "<<ans<<endl;
    ans = bestPriceEfficient(arr);
    cout<<"ans: "<<ans<<endl;
}
int bestPrice(vector<int>&arr, int start, int end)
{
    
    if(start > end)
        return 0;
    int ans =0;
    for(int i = start; i < end; i++)
    {
        for(int j = i + 1; j <= end; j++)
        {
            if(arr[j] > arr[i])
            {
            int ra = arr[j] - arr[i] + bestPrice(arr, start, start -1) + bestPrice(arr, j + 1, end);
                if(ra > ans)
                    ans = ra;
            }
        }
    }
    return ans;
}
int bestPriceEfficient(vector<int>&arr)
{
    int n = arr.size();
    int profit = 0;
    for(int i = 1; i <n; i++)
    {
        //int prevIndex = i - 1;
        if(arr[i] > arr[i - 1])
        {
          //  cout<<"arr[i]: "<<arr[i]<<" arr[i - 1]: "<<arr[i - 1]<<endl;
            profit += arr[i] - arr[i - 1];
            //cout<<"profit : "<<profit<<endl;
        }
    }
    //cout<<"profit"<<endl;
    return profit;
}