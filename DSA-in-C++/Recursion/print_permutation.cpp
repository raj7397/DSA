#include <iostream>
#include <string>

using namespace std;

void print_permutation(string str,int);
void swap(string &str, int i ,int j);
int main(int argc, char **argv)
{
    string str;
    cin>>str;
    print_permutation(str,0);
}
void print_permutation(string str,int idx)
{
    if(idx >= str.length()-1)
    {
        cout<<str<<endl;
        return;
    }
    for(int i = idx; i < str.length(); i++)
    {
        swap(str, i, idx);
        print_permutation(str, idx+1);
        swap(str, i, idx);
    }
}
void swap(string &str, int i, int j)
{
    int t = str[i];
    str[i] = str[j];
    str[j] = t;
}