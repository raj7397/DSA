#include <iostream>
#include <string>

#include <stack>
using namespace std;
string smallestNum(string );
int main(int argc, char ** argv)
{
    string str;
    cin>>str;
    string ans = smallestNum(str);
    cout<<ans<<endl;
}
string smallestNum(string str)
{
    stack<int> st;
    int num = 1;
    string ans = "";
    for(int i = 0 ; i < str.length(); i++)
    {
        if(str[i] == 'd')
        {
            st.push(num);
            num++;
        }
        else{
            st.push(num);
            num++;
            while(st.size() > 0)
            {
                char c = (char)st.top();
                st.pop();
                char ch = c + '0';
                ans = ans + ch;
           //     ans = ans + (st.top()+ '0');
            }
        }
    }
    st.push(num);
    while(st.size() > 0)
    {
        char c = (char)st.top();
        st.pop();
        char ch = c + '0';
        ans = ans +ch;
    }
    return ans;
}