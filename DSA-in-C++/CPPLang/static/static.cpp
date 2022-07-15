#include <iostream>
#include <string>

using namespace std;
class Loan{
    private:
        static int roi;
        int percentage;
    public:
        static void showRoi()
        {
           // percentage = 30;
            cout<<"roi: "<<roi<<endl;
        }
        void display()
        {
            roi = 30;
            cout<<"display roi: "<<roi<<endl;
        }
};
int Loan:: roi = 5;
int main(int argc, char **argv)
{
    Loan loan;
    loan.showRoi();
    loan.display();
    loan.showRoi();
    Loan::showRoi();
  //  Loan::display();
}