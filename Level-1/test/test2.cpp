#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int compute(int a, int b, string oper)
{
    if(oper == "+")
    {
        return a+b;
    }
    else if(oper == "-")
    {
        return a-b;
    }
    else if(oper == "*")
    {
        return a*b;
    }
    else{
        return a/b;
    }
}

int evalRPN(vector<string> &A) {
    stack<int> st;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] == "+" || A[i] == "-" || A[i] == "/" || A[i] == "*")
        {
          int v2 = st.top();
            st.pop();
            int v1 = st.top();
            st.pop();
            int res = compute(v1, v2, A[i]);
            st.push(res);
            
         //   string temp = A[i];
           // stringstream geek(temp);
            //int x = 0;
            //geek >> x;
          //  
          //  cout<<" x: "<<opnd<<endl;
        }

        else{
        //    cout<<"A[i]: "<<A[i]<<endl;
            int opnd = stoi(A[i]);
            st.push(opnd);
  
        }
    }
 //   cout<<"st.top():"<<st.top()<<endl;
    return st.top();
}
int main(int argc , char **argv)
{
    vector<string>inp;
    inp.push_back("2");
    inp.push_back("2");
    inp.push_back("/");
    cout<<"res: "<<evalRPN(inp)<<endl;
}