#include <iostream>
#include <vector>

using namespace std;
int findPivot(vector<int>&arr);
int main(int argc, char **argv)
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int pivotPos = findPivot(arr);
    cout<<"pivotPos: "<<pivotPos<<endl;
}
int findPivot(vector<int>&arr)
{
    int left = 0, right = arr.size() - 1;
    while(left <= right)
    {
        int mid = (left + right)/2;
       // cout<<"mid: "<<mid<<endl;
        if(mid < right && arr[mid] > arr[mid + 1])
            return mid;
        if(left < mid && arr[mid - 1] > arr[mid])
            return mid - 1;
        if(arr[left] <= arr[mid])
            left = mid + 1;
        else{
            right = mid - 1;
        }
    }
    return -1;
}