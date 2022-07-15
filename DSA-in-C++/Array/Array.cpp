#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_groups(vector<int> &arr)
{
    int count0 = 0;
    int count1 = 0;
    int i = 0;
    while(i < arr.size())
    {
        if(arr[i] == 0)
        {
            count0++;
            while(arr[i] == 0)
                i++;
        }
        else if(arr[i] == 1)
        {
            count1++;
            while(arr[i] == 1)
                i++;
        }
    }
    cout<<"0: "<<count0<<endl;
    cout<<"1: "<<count1<<endl;
}
int main(int argc, char **argv)
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n;i++)
        cin>>arr[i];
    print_groups(arr);
}
