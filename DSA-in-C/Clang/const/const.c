#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv)
{
    const int a = 10;
    int *ptr = &a;
    *ptr = 20;
    printf("*ptr : %d a : %d",*ptr,a);
}