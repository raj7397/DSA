#include <iostream>
#include <string>

using namespace std;
void solve_fibo_r();
int fibo_r(int);

int main(int argc, char **argv)
{
    solve_fibo_r();
}
void solve_fibo_r()
{
    int n;
    cin>>n;
    int ans = fibo_r(n);
    cout<<"ans: "<<ans<<endl;
}
int fibo_r(int n)
{
    if(n == 0 || n == 1)
        return n;

    int a1 = fibo_r(n - 1);
    int a2 = fibo_r(n - 2);
    return a1 + a2;
}