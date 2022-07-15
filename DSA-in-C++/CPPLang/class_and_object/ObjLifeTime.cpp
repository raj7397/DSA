#include <iostream>
#include <string>

using namespace std;

class Complex{
    int re_;
    int im_;
    public:
    Complex(int re, int im):re_(re),im_(im){
        cout<<"Complex constructor: "<<endl;
    }
    ~Complex()
    {
        cout<<"Complex destructor: "<<endl;
    }
    void print()
    {
        cout<<"re: "<<re_<<" im: "<<im_<<endl;
    }

};
//static Complex c1(3.4,36);
int main(int argc, char **argv)
{
    Complex c1(33,44);
    c1.print();
    //char buffer[100];
    //Complex *ptr = new (buffer) Complex(11,33);
    //ptr->print();
    //cout<<"main starts: "<<endl;
    //static Complex c1(3,4);
    //c1.print();

    
    cout<<"Main ends"<<endl;
}