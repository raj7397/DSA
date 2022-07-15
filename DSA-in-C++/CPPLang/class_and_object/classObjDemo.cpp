#include <iostream>
#include <string>

using namespace std;
class myClass{
    public:
        int id;
        int roll;
        myClass(int id,int roll)
        {
            this->id = id;
            this->roll = roll;
            cout<<"in constructor: "<<endl;
        }
};
struct myStudy{
    int sub;
    int id;
    myStudy(int sub,int id)
    {
        this->sub = sub;
        this->id = id;
        cout<<"struct consturctor: "<<endl;
    }
};
int main()
{
    myClass mc2 = {33,333};
    myStudy ms = {12,22};
    cout<<"ms.sub: "<<ms.sub<<" ms.id: "<<ms.id<<endl;
    myClass mc = {4,34};// this will be passed as paramter to constructor
    cout<<"mc.id: "<<mc.id<<" mc.roll: "<<mc.roll<<endl;
}