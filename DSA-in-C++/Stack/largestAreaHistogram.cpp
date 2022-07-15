#include <iostream>
#include <string>

using namespace std;
int largest_area_hist_n2(int *arr, int n);
int main(int argc, char ** argv)
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int ans = largest_area_hist_n2(arr,n);
    cout<<"ans: "<<ans;
}
int largest_area_hist_n2(int arr[], int n)
{
    int max_area = 0;
    for(int i = 0; i < n; i++)
    {
        int j = i - 1;
        for(; j >=0 ; j--)
        {
            if(arr[j] < arr[i])
            {
                break;
            }
        }
        int k = i + 1;
        for(; k < n; k++)
        {
            if(arr[k] < arr[i])
                break;
        }
        cout<<"j: "<<j<<" k: "<<k<<endl;
        if(j != -1)
        {
            max_area = max(max_area, arr[i]*(k - j -1));
        }
        else if(j == -1)
        {
            max_area = max(max_area, arr[i] * k);
        }
        cout<<"max area: "<<max_area<<endl;
        //else if()
    }
    return max_area;
}