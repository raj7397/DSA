#include <iostream>
#include <vector>

using namespace std;
void sorted_insert(vector<int>&arr1,int i, int x)
{
   // cout<<"x: "<<x<<endl;
    int j = i - 1;
    while(j >= 0 &&arr1[j] > x)
    {
        j--;
    }
    j++;
    arr1.insert(arr1.begin() + j, x);

}
void merge(vector<int>&arr1, vector<int>&arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    if(n == 0)
    {
        arr1 = arr2;
        return;
    }
    else if(m == 0)
    {
        return;
    }
    int i = 0, j = 0;
    while(i < arr1.size() && j < m)
    {
        if(arr1[i] <= arr2[j])
        {
            i++;
        }
        else{
            sorted_insert(arr1,i,arr2[j]);
            i++;
            j++;
        }
    }
    if(i == arr1.size())
    {
        while(j < m)
        {
            arr1.push_back(arr2[j]);
            j++;
        }
    }
 /*   if(j == m)
    {
        while(i < n)
        {
            arr1.push_back
        }
    }*/
}
int main(int argc, char ** argv)
{
    int n,m;
    cin>>n;
    vector<int>arr1(n);
    for(int i = 0; i < n; i++)
        cin>>arr1[i];
    //int m;
    cin>>m;
    vector<int>arr2(m);
    for(int i = 0; i < m; i++)
        cin>>arr2[i];
    cout<<"After merge"<<endl;
    merge(arr1,arr2);
    for(int i = 0; i< arr1.size();i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
}