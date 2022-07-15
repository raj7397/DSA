#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int arc, char ** argv)
{
    vector<int>arr={1,5,10,15,20};
    cout<<"Array before insert"<<endl;
    for(int i = 0; i < arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    arr.insert(arr.begin() + 2,7);
    cout<<"After insert:"<<endl;
   for(int i = 0; i < arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}