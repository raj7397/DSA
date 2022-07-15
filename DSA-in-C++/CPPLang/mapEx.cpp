#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

int main(int argc, char ** argv)
{
    unordered_map<string, int> myMap;
    myMap.insert(make_pair("Rajkalash",33));
    myMap.insert({"Rajkamal",32});
    myMap.insert({"Koushilya",44});
    myMap["Sita"] = 29;
    if(myMap.find("Geeta") != myMap.end())
    {
        cout<<"Not found: "<<endl;
    }
    if(myMap.find("Sita") != myMap.end())
    {
    
        unordered_map<string, int>:: iterator itr = myMap.find("Sita");
     //   pair<string, int> ele = myMap.find("Sita");
        //cout<<"ele.val: "<<ele.second<<endl;
        cout<<"fuond:"<<endl;
   //     cout<<"key: "<<itr->first<<" val: "<<itr->second<<endl;
    }
    for(auto ele: myMap)
    {
        cout<<"Key: "<<ele.first<<" Second: "<<ele.second<<endl;
    }
}