#include <iostream>
#include <string>
#include <vector>

using namespace std;
int max_length_substr(string str)
{
    vector<int>prev(256,-1);
    int start = 0,ans = 0;
    for(int end = 0; end < str.length(); end++)
    {
        start = max(start, prev[str[end]] + 1);
        int maxEnd = end - start + 1;
        ans = max(ans, maxEnd);
        prev[str[end]] = end;
    }
    return ans;
}
int main(int argc, char ** argv)
{
    string str;
    cin>>str;
    int ans = max_length_substr(str);
    cout<<"ans: "<<ans<<endl;
}