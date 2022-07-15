#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    unordered_map<int,vector<int>>hm;
    hm[1].push_back(20);
    hm[2].push_back(30);
    hm[1].push_back(300);
    for(auto a: hm[1])
        cout<<"a: "<<a<<endl;
}