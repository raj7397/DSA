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
        cout<<"Normal constructor: "<<endl;
       // cout<<"add of c1:"<<(&c1)<<endl;
        cout<<" add of this: "<<(this)<<endl;
    }
    Complex(const Complex &c1)
    {
        this->re = c1.re;
        this->im = c1.im;
        cout<<"Copy constructor: "<<endl;
        cout<<"add of c1:"<<(&c1)<<endl;
        cout<<" add of this: "<<(this)<<endl;
    }
    ~Complex()
    {
        cout<<"Destructor: "<<endl;
        cout<<"this: "<<(this)<<endl;
        this->showDetail();
        
    }
    Complex  operator = (const Complex & c)
    {
        cout<<"Coppy assignment started: "<<endl;
        cout<<"add of c: "<<(&c)<<endl;
        cout<<"add of this: "<<(this)<<endl;
        this->re = c.re;
        this->im = c.im;
        cout<<"Coppy assignment: ended "<<endl;
        return *this;
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
    Complex c1(111,222),c2(333,444);//,c3(555,666);
    cout<<"Before assign: "<<endl;
    cout<<"c2 data: "<<endl;
    c2.showDetail();
    //cout<<"c3 data: "<<endl;
    //c3.showDetail();
    c2 = c1;
    cout<<"--------------------------------"<<endl;
    cout<<"c2 data: "<<endl;
    c2.showDetail();
   // cout<<"c3 data: "<<endl;
    //c3.showDetail();
    //Complex c4(c1);
    //Complex c3 = c2;
    //fun(c3);
   // Complex c4(77,88);
   //  fun2();
}