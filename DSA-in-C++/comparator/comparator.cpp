#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*int n = 10;
int a[]={8,89,2,1,-90,4343,2343,999,2439,-90};
 int call = 0;*/
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
void print()
{
    cout<<"---------------------------"<<endl;
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout<<"\n---------------------------"<<endl;
}
class FunComp
{
public:
    bool operator()(int a,int b)
    {
        cout<<"a: "<<a<<" b: "<<b<<endl;
        cout<<"call: "<<call<<endl;
        cout<<"printing array:"<<endl;
        print();
        call++;
        if(b > a)
            return true;
        return false;
       // return a>b;
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
            
            if(t[0] < last[1])
            {
                //ans.pop_back();
                last[1] = max(t[0], last[1]);
                
                //ans.push_back(last);
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
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }
    merge(arr);
 /*   cout<<"Printing the vector:"<<endl;
    print_2d(arr);
    cout<<"after sort: "<<endl;
    sort(arr.begin(), arr.end(), vComp());
    print_2d(arr);*/


   // int a[]={8,89,2,1,-90,4343,2343,999,2439,-90};
 //   sort(a,a+9,FunComp());


}