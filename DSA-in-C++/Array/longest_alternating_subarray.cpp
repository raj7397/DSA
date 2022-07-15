#include <iostream>
#include <vector>
#include <string>

using namespace std;

int max_alter(vector<int>& arr)
{
    int n = arr.size();
         int ans = 1;
        int count = 1;
        for(int i = 1; i < n; i++)
        {
            int val = arr[i];
            int val1 = arr[i - 1];
            int rem1 = val % 2;
            int rem2 = val1 % 2;
            cout<<arr[i] % 2<<" "<<arr[i - 1] % 2<<" "<<endl;
            bool cond1 = (arr[i] % 2 == 0 && arr[i - 1] % 2 != 0);
            bool cond2 = (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0);
            cout<<" cond1: "<<cond1<<" cond2: "<<cond2<<endl;
            bool cond = cond1 || cond2;
            cout<<"cond: "<<cond<<endl;         
            if(cond == true)
            {
                cout<<"inside true: "<<endl;
                count++;
                cout<<" count "<<count<<endl;
            }
            else{
                ans = max(ans, count);
                count = 1;
            }
        }
        return max(ans,count);
}
int main(int argc, char ** argv)
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int ans = max_alter(arr);
    cout<<"ans: "<<ans<<endl;
}
