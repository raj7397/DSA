#include <iostream>
#include <string>
#include <vector>

using namespace std;
void print_median_in_stream(vector<int> &arr);
int main(int argc, char ** argv)
{
    int n,t; 
    cin>>n;
    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        cin>>t;
        arr.push_back(t);
    }
    cout<<"Print array: "<<endl;
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    print_median_in_stream(arr);
}
void print_median_in_stream(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp(n);
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            temp[i] = arr[i];
        }
        else{
            int key = arr[i];
            int j = i - 1;
            while(j >= 0 && temp[j] > key)
            {
                temp[j + 1] = temp[j];
                j--;
            }
            temp[j + 1] = key;
        }
        if(i % 2 ==0)
        {
            cout<<(double)temp[(i + 1)/2]<<" ";
        }
        else{
            double res = (double)(temp[(i + 1)/2] + temp[i/2])/2;
            cout<<res<<" ";
        }
    }
    cout<<endl;
}