#include <iostream>
#include <stdlib.h>

using namespace std;
void * operator new (size_t n)
{
    cout<<"overloading new: "<<endl;
    void *ptr;
    ptr = malloc(n);
    return ptr;
}
void operator delete(void *ptr)
{
    cout<<"overloading delete"<<endl;
    free(ptr);
}
int main(int argc, char **argv)
{
    int *p = new int;
    *p = 30;
    cout<<(*p)<<endl;
    delete p;

}