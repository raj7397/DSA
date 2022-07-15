#include <iostream>
#include <string>
#include <stack>
using namespace std;

void solve_valid_parenthesis();
bool is_valid_paren(string str);
int main(int argc, char ** argv)
{
    solve_valid_parenthesis();
}
void solve_valid_parenthesis()
{
    stack<int> st;
    st.push(10);
    cout<<" empty: "<<st.empty()<<endl;
    string str;
    cin>>str;
    cout<<"str: "<<str<<endl;
    bool ans = is_valid_paren(str);
    cout<<"ans: "<<ans<<endl;
}
bool is_valid_paren(string str)
{
    stack<char> st;
    for(int i = 0 ; i < str.length(); i++)
    {
        if(str[i]== '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if(st.empty())
                return false;
            else
            {
                if(st.top() == '(' && str[i] == ')' || st.top() == '{' && str[i] == '}' || st.top() == '[' && str[i] == ']' )
                {
                    cout<<"pop: "<<endl;
                    st.pop();
                }
                else{
                    return false;
                }
            }

        }
    }
    if(st.empty())
        return true;
    return false;
}