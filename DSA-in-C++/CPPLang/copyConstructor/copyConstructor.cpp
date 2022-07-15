#include <iostream>
#include <string>

using namespace std;


class Complex{
    int re;
    int im;
    public:
    Complex(int re, int im)
    {
        this->re = re;
        this->im = im;
        cout<<"Parameter constructor: "<<endl;
    }
    Complex(const Complex &c1)
    {
        this->re = c1.re;
        this->im = c1.im;
        cout<<"Copy constructor: "<<endl;
    }
    ~Complex()
    {
        cout<<"Destructor: "<<endl;
        this->showDetail();
    }
    void showDetail()
    {
        cout<<"re: "<<re<<" im: "<<im<<endl;
    }
};
void fun(Complex c)
{
    cout<<"Inside fun: "<<endl;
    c.showDetail();
    cout<<"fun done: "<<endl;
}
Complex fun2()
{
    cout<<"inside fun2(): "<<endl;
    Complex c(99,111);
    return c;
}
int main(int argc, char ** argv)
{
   // Complex c1(11,22),c2(33,44),c3(55,66);
    //Complex c4(c1);
    //Complex c3 = c2;
    //fun(c3);
   // Complex c4(77,88);
     fun2();
}