#include <iostream>
#include <vector>

using namespace std;
int search_in_sorted_rotated(vector<int>&arr,int x);
int main(int argc, char **argv)
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    int pos = search_in_sorted_rotated(arr, x);
    cout<<"pos: "<<pos<<endl;
}
int search_in_sorted_rotated(vector<int>&arr,int x)
{
    int left = 0, right = arr.size() - 1;
    while(left <= right)
    {
        int mid = (left + right)/2;
        if(x == arr[mid])
            return mid;
        if(arr[left] <= arr[mid])
        {
            if(x >= arr[left] && x <= arr[mid])
                right = mid -1;
            else{
                left = mid + 1;
            }
        }
        else{
            if(x >= arr[mid] && x <= arr[right])
                left = mid + 1;
            else{
                right = mid -1;
            }
        }
    }
    return -1;
}