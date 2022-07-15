#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void print_2d(vector<vector<int>> &arr);
void print_2d(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
class vComp{
    public:
    bool operator()(vector<int> a, vector<int>b)
    {
        int i = 0;
        int j = 0;
        while(i < a.size() && j < b.size())
        {
            if(b[i] <= a[j])
                return true;
            i++;
            j++;
        }
        return false;
    }
};

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
        {
            vector<int> t = intervals[i];
            vector<int> last = ans.back();
            
            if(t[0] <= last[1])
            {
                ans.pop_back();
                last[1] = max(t[1], last[1]);
                
                ans.push_back(last);
            }
            else{
                ans.push_back(t);
            }
        }
        print_2d(ans);
        return ans;
        
}
int main(int argc, char **argv)
{
    vector<vector<int>>t;
    vector<int>a;
    a.push_back(1);
    a.push_back(2);
    t.push_back(a);
    int x = a.back();
    x = 70;
    cout<<"last[0]: "<<a[0]<<" last[1]: "<<a[1]<<endl;

    vector<int> last = t.back();
    last[1] = 300;
    cout<<"last[0]: "<<last[0]<<" last[1]: "<<last[1]<<endl;
    for(int i =0; i < t.size(); i++)
    {
        for(int j = 0; j < t[0].size(); j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
   /* int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }
    merge(arr);*/
}