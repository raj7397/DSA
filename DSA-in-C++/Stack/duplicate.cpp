//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;
bool is_duplicate(string str)
{
   stack<char> st;
   for(int i = 0; i < str.length(); i++)
   {
      if(str[i] != ')')
      {
         st.push(str[i]);
      }
      else{
         if(st.top() == '(')
            return true;
         while(st.empty() == false && st.top() != '(')
         {
            cout<<"top: "<<st.top()<<endl;
            st.pop();
         }
         st.pop();
      }
   }
   return false;
}
int main(int argc, char **argv)
{ 
   string str;
   cin>>str;
   cout<<"input: "<<str<<endl;
   bool ans = is_duplicate(str);
   cout<<ans<<endl;
   //write your code
   return 0;
} 