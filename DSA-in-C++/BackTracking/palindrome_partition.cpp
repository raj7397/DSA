#include <iostream>
#include <string>

using namespace std;
void palindrome_partition(string str, int start, string asf);
bool isPalindrome(string str, int i , int j)
{
    while(i < j)
    {
        if(str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(int argc, char ** argv)
{
    string str;
    cin>>str;
    palindrome_partition(str,0, "");
}
void palindrome_partition(string str, int start, string asf)
{
    if(start == str.length())
    {
        cout<<asf<<endl;
        return;
    }


    for(int i = start; i < str.length(); i++ )
    {
        if(isPalindrome(str, start, i))
        {
            palindrome_partition(str, i + 1, asf + "(" + str.substr(start, i - start + 1) + ")");
        }
    }
}