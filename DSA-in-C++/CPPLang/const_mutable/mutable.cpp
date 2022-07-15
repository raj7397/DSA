#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Complex{
    int x;
    mutable int mutMem;
    public:
    Complex(int x,int y):x(x),mutMem(y)
    {
        cout<<"Constructor:"<<endl;
    }
    void showX()
    {
        cout<<"x: "<<x<<endl;
    }
    void changeMut(int i) const{
        mutMem  = i;

    }
    int getMem()const{
        return mutMem;
    }
};
void disp(auto &v)
{
    for(int i  = 0; i < v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int>arr = {20,30,40};
    disp(arr);
   /* Complex c1(11,22);
    Complex c2(33,44);
    
    c2.changeMut(5);
    cout<<"c1.mut: "<<(c1.getMem())<<endl;*/
   // c2.showX();
}