#include <iostream>
#include <string>
#include <stack>

using namespace std;
void eval_postfix_and_convert_infix_prefix(string exp);
int calculate_val(int a, int b, char opr)
{
    if(opr == '+')
        return a+b;
    else if(opr == '-')
    {
        return a-b;
    }
    else if(opr == '*')
    {
        return a*b;
    }
    else{
        return a/b;
    }
}
int main(int argc, char ** argv)
{
    string exp;
    cin>>exp;
    eval_postfix_and_convert_infix_prefix(exp);
}
void eval_postfix_and_convert_infix_prefix(string exp)
{
    stack<char> operand;
    stack<string> infix;
    stack<string> prefix;
    for(int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];
        if(ch >= '0' && ch <= '9')
        {
            string temp = "";
            temp = temp + ch;
            operand.push(ch);
            infix.push(temp);
            prefix.push(temp);
        }
        else {
            if(operand.size() > 0)
            {
                char b = operand.top();
                operand.pop();
                char a = operand.top();
                operand.pop();
                char opr = ch;
               // int c = (int)a;
               // int d = (int)b;
                int res = calculate_val(a - '0',b - '0', ch );
                operand.push(res + '0');
                string inf_b = infix.top();
                infix.pop();
                string inf_a = infix.top();
                infix.pop();
                string inf_exp = "(" + inf_a + opr+ inf_b + ")";
                infix.push(inf_exp);
                 string pre_b = prefix.top();
                prefix.pop();
                string pre_a = prefix.top();
                prefix.pop();
                string pre_exp = opr + pre_a + pre_b;
                prefix.push(pre_exp);
                //int b = st
            }
        }

    }
    cout<<operand.top()<<endl;
    cout<<infix.top()<<endl;
    cout<<prefix.top()<<endl;
}
