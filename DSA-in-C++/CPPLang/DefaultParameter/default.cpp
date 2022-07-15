#include <iostream>
#include <string>

using  namespace std;
int fun(int a = 10, int b = 30)
{
    cout<<"a: "<<a<<" b: "<<b<<endl;
    return a+b;
}
int main(int argc,char ** argv)
{
    int x = 200;
    int b = fun(x);
}