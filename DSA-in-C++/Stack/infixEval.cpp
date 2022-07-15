#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

bool isOperator(char ch);
int precedence(char ch);
int evaluate_infix(string exp);
int calculate_val(int a, int b, char opr);
int main(int argc, char **argv)
{
    string exp;
    cin>>exp;
    int ans = evaluate_infix(exp);
    cout<<ans<<endl;
}
int evaluate_infix(string exp)
{
    stack<int>operand;
    stack<char> opertr;
    for(int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];
        if(ch == '(')
        {
            opertr.push(ch);
        }
        else if(ch >= '0' && ch <= '9')
        {
            operand.push(ch - '0');
        }
        else {
            if(isOperator(ch))
            {
                while(opertr.size() > 0 && opertr.top() != '(' && precedence(ch) <= precedence(opertr.top()))
                {
                    int second = operand.top();
                    operand.pop();
                    int first = operand.top();
                    operand.pop();
                    char opr = opertr.top();
                    opertr.pop();
                    int res = calculate_val(first, second,opr);
                    //cout<<"res: "<<res<<endl;
                    operand.push(res);

                }
                opertr.push(ch);
            }
            else if(ch == ')')
            {
               while(opertr.size() > 0 && opertr.top() != '(')
                {
                    int second = operand.top();
                    operand.pop();
                    int first = operand.top();
                    operand.pop();
                    char opr = opertr.top();
                    opertr.pop();
                 //   cout<<"first: "<<first<<" second: "<<second<<" opr: "<<opr<<endl;
                    int res = calculate_val(first, second,opr);
                   // cout<<"res: "<<res<<endl;
                    operand.push(res);

                }
                opertr.pop();

            }
        }
    }
    while(opertr.size() > 0)
    {
                    int second = operand.top();
                    operand.pop();
                    int first = operand.top();
                    operand.pop();
                    char opr = opertr.top();
                    opertr.pop();
                    int res = calculate_val(first, second,opr);
                    operand.push(res);

    }
    return operand.top();
}
bool isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    return false;
}
int precedence(char ch)
{
   if(ch == '+' || ch == '-')
        return 1;
   if(ch == '*' || ch == '/')
        return 2;
    return 2;
   
}
int calculate_val(int a, int b, char opr)
{
    if(opr == '+')
        return a+b;
    else if(opr == '-')
        return a-b;
    else if(opr == '*')
        return a*b;
    else
        return a/b;
}