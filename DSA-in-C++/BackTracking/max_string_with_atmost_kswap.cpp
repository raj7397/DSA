#include <iostream>
#include <string>

using namespace std;
void swap(string &str, int i, int j)
{
    char t = str[i];
    str[i] = str[j];
    str[j] = t;
}
void max_string_with_atmost_kswap(string str, string &ans, int index, int k);
int main(int argc, char ** argv)
{
    string str;
    cin>>str;
    string ans = str;
    int k;
    cin>>k;
    max_string_with_atmost_kswap(str, ans, 0,k);
    cout<<"ans: "<<ans<<endl;
}
void max_string_with_atmost_kswap(string str, string &ans, int index, int k)
{

    if(k == 0 || index == str.length())
        return ;


    char maxChar = str[index];
    int pos = index;
    for(int i = index; i < str.length(); i++)
    {
        if(str[i] > maxChar)
            maxChar = str[i];
    }
    if(maxChar != str[index])
        k--;
    for(int i = str.length() -1 ; i >= index; i--)
    {
        if(str[i] == maxChar)
        {
            swap(str, index, i);
                if(str > ans)
                     ans = str;
            max_string_with_atmost_kswap(str, ans, index + 1, k);
            swap(str, index, i);
        }
    }

}