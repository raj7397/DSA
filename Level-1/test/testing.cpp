#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

int main(int argc, char **argv)
{
    vector<int> v1{2};
    vector<int>v2{2};
    vector<int>v3;
    vector<int>v4{2,2};
    vector<int>v5{1,2,2};
    vector<int>v6{1,2,2};
    vector<int>v7{1};
    vector<int>v8{1,2};
    set<vector<int>>res;
    res.insert(v1);
    res.insert(v2);
    res.insert(v3);
    res.insert(v4);
    res.insert(v5);
    res.insert(v6);
    res.insert(v7);
    res.insert(v8);
    for( auto s : res)
    {
        for(auto x : s)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }

 //  sort(res.begin(),res.end());
   vector<vector<int>> res1(res.begin(),res.end());
    for(int i = 0; i < res1.size();i++)
    {
        for(auto x: res1[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<"Testing the hypthesis"<<endl;
    cout<<"Testing the hypo"<<endl;

}