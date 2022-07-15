#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.erase(0);
    cout<<"After erase: "<<endl;
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
  /*  string str = "abc";
    str.erase(2);
    cout<<"str: "<<str<<endl;
    str.erase(1);
    cout<<"str: "<<str<<endl;
    str.erase(0);
    cout<<"str: "<<str<<endl;*/
}