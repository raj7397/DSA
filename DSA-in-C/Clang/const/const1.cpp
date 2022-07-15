#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define SQUARE(x) (x*x)
int main(int argc, char ** argv)
{
    int b = 4;
    int c= SQUARE(++b);
    cout<<"c: "<<c<<endl;
    char *name = "Rajkalash";
    char * name2 = strdup(name);
    printf("name2: %s",name2);
  /*  const int a = 10;
    int *ptr = &a;
    *ptr = 20;
    printf("*ptr : %d a : %d",*ptr,a);*/
}