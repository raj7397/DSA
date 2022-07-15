#include <iostream>
#include <string>
#include <stack>
using namespace std;
void print_postfix_prefix(string exp);
int precedence(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/')
        return 2;
    return 2;
}
bool isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch =='/')
        return true;
    return false;
}
int main(int arg, char **argv)
{
    string exp;
    cin>>exp;
    print_postfix_prefix(exp);
}
void print_postfix_prefix(string exp)
{
    stack<string> postfix;
    stack<string> prefix;
    stack<char> opertr;
    for(int i =0; i < exp.length(); i++)
    {
        if(exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z' || exp[i] >= '0' && exp[i] <= '9')
        {
            string temp = "";
            temp= temp + exp[i];
            postfix.push(temp);
            prefix.push(temp);
        }
        else if(exp[i] == '(')
        {
            opertr.push(exp[i]);

        }
        else{
            if(exp[i] == ')')
            {
                while(opertr.size() > 0 && opertr.top() != '(')
                {
                    string post_b = postfix.top();
                    postfix.pop();
                    string post_a = postfix.top();
                    postfix.pop();
                    char opr = opertr.top();
                    opertr.pop();
                    string exp1 = post_a + post_b + opr;
                    postfix.push(exp1);
                    string pre_b = prefix.top();
                    prefix.pop();
                    string pre_a = prefix.top();
                    prefix.pop();
                    string exp2 = opr + pre_a + pre_b;
                    prefix.push(exp2); 
                }
                opertr.pop();
            }
            else{
                if(isOperator(exp[i]))
                {
                    while(opertr.size() > 0 && opertr.top() != '(' && precedence(exp[i]) <= precedence(opertr.top()))
                    {
                        string post_b = postfix.top();
                        postfix.pop();
                        string post_a = postfix.top();
                        postfix.pop();
                        char opr = opertr.top();
                        opertr.pop();
                        string exp1 = post_a + post_b + opr;
                        postfix.push(exp1);
                        string pre_b = prefix.top();
                        prefix.pop();
                        string pre_a = prefix.top();
                        prefix.pop();
                        string exp2 = opr + pre_a + pre_b;
                        prefix.push(exp2); 
                   }
                   opertr.push(exp[i]);

                }
            }
        }
    }
     while(opertr.size() > 0 )
    {
                        string post_b = postfix.top();
                        postfix.pop();
                        string post_a = postfix.top();
                        postfix.pop();
                        char opr = opertr.top();
                        opertr.pop();
                        string exp1 = post_a + post_b + opr;
                        postfix.push(exp1);
                        string pre_b = prefix.top();
                        prefix.pop();
                        string pre_a = prefix.top();
                        prefix.pop();
                        string exp2 = opr + pre_a + pre_b;
                        prefix.push(exp2);
     }

     cout<<postfix.top()<<endl;
     cout<<prefix.top()<<endl;
}
