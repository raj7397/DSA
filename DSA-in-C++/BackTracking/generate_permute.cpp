#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;

}
void permuteHelper(vector<int> & A, int idx, vector<vector<int>> &ans)
{
    if(idx == A.size())
    {
        ans.push_back(A);
        return;
    }
    for(int i = idx ; i < A.size(); i++)
    {
        swap(A[idx], A[i]);
        permuteHelper(A, idx + 1, ans);
        swap(A[idx], A[i]);
    }
}

int main(int argc, char **argv)
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i =0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<vector<int>> ans;
    permuteHelper(arr, 0 , ans);
    cout<<"all permutation: "<<endl;
    for(int i =0 ; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

