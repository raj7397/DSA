#include <iostream>
#include <stdlib.h>

using namespace std;
int main(int argc , char **argv)
{
    char buffer[8];
    int *p = new (buffer)int(1026);
    int *q = new (buffer + sizeof(int))int(50);
    cout<<"*pr: "<<(*p)<<"(*q): "<<(*q)<<endl;
    cout<<"val: "<<(*buffer)<<endl;
    for(int i = 0; i < 8;i++)
    {
        cout<<(int)buffer[i]<<endl;
    }
}