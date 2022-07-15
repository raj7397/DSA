#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str="";
    string str2="";
    reverse(str.begin(),str.end());
    str+=str2;
    int count = 0;
    int size = str.size() -1;
    cout<<"size: "<<size<<endl;
    int k = 0;
    for(k = 0; k < -1; k++)
    {
        cout<<"k: "<<endl;
    }
    bool x = k < (str.size() - 1);
    for(int k  = 0; k < (str.length() - 1); k++)
    {
        if(str[k] != str[k + 1])
            count++;
    }
    cout<<"count: "<<endl;
    cout<<"str: "<<str<<endl;
}