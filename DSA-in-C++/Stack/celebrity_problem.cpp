#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
int is_all_0(string arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] != '0')
            return -1;
        
    }
    return 0;
}
bool is_all_1(vector<string> & arr, int k)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(i != k && arr[i][k] == '0')
            return false;
    }
    return true;
}
int find_celebrity(vector<string>&arr)
{
    int n = arr.size();
    //int m = arr[0].size();
    for(int i = 0; i < n; i++)
    {
        int idx = is_all_0(arr[i]);
        if(idx != -1)
        {
            if(is_all_1(arr ,i))
                return i;
        }
    }
    return -1;
}
int find_celeb2(vector<string> & arr)
{
    int n = arr.size();
    stack<int> st;
    for(int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while(st.size() >= 2)
    {
        int j = st.top();
        st.pop();
        int i = st.top();
        st.pop();
        if(arr[i][j] == '1')
        {
            st.push(j);
        }
        else{
            st.push(i);
        }
    }
    int pc = st.top();
    bool isCeleb = true;
    for(int i = 0; i < n; i++)
    {
        if(pc != i && arr[pc][i] == '1')
        {
            isCeleb =  false;
            break;
        }

    }
    if(isCeleb)
    {
        for(int i = 0; i < n; i++)
        {
            if(pc != i && arr[i][pc] == '0')
            {
                isCeleb = false;
            }
        }
    }
    if(isCeleb)
        return pc;
    return -1;
}

int main(int argc, char ** argv)
{
    int n;
    cin>>n;
   // vector<vector<int>>arr(n,vector<int>(m));
    vector<string>arr(n);
    for(int i =0 ; i < n; i ++)
    {
        cin>>arr[i];
    }
    int ans1 = find_celeb2(arr);
    if(ans1 != -1)
        cout<<ans1<<endl;
    else
        cout<<"none"<<endl;
    /*int ans = find_celebrity(arr);
    if(ans != -1)
        cout<<ans<<endl;
    else
        cout<<"none"<<endl;*/
}