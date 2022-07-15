#include <iostream>
#include <string>
using namespace std;

class Test{
//private:
public:
    int a;
    int b;
//public:
    Test(int a,int b)
    {
        this->a = a;
        this->b = b;
        cout<<"Default constructor "<<endl;
    }
    void show();
    int sum(int,int);
};
void Test::show()
{
    cout<<"a: "<<a<<" b: "<<b<<endl;
}
int Test::sum(int a,int b)
{
    cout<<" sum: "<<endl;
    return a+b;
}
int main(int argc, char **argv)
{
    Test t1(44,55);
    //Test t = {11,22};
  //  cout<<"t.a: "<<(t.a)<<" t.b: "<<(t.b)<<endl;
    t1.show();
    int s = t1.sum(2,3);
    cout<<"s: "<<s<<endl;
}