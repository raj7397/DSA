#include <iostream>
#include <string>

using namespace std;
void print_encoding(string str, string asf);
int main(int argc, char ** argv)
{
    string str;
    cin>>str;
    print_encoding(str,"");
}
void print_encoding(string str, string asf)
{
    if(str.length() == 0)
    {
        cout<<asf<<endl;
        return ;
    }

    if(str[0] == '0')
        return ;
    char ch1 = str[0];
    string ros = str.substr(1);
    int d1 = ch1 - '0';
    char passChar = (char)('a' + (d1 - 1));
    print_encoding(ros,asf + passChar);
    if(str.length() >= 2)
    {
        char ch2 = str[1];
        string ros2 = str.substr(2);
        int d2 = ch2 - '0';
        int num = d1 * 10 + d2;
        if(num <= 26)
        {
            char passChar2 = (char)('a' + (num -1));
            print_encoding(ros2, asf +passChar2);
        }
    }

}