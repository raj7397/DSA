#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int a;
const int b = 20;
int c = 20;
int main()
{
    int *ptr = malloc(19);
    int x = 10;
    while(1)
    {
	printf("bss a = %p, read only b = %p, data c = %p",&a,&b,&c);
	printf("stack x = %p ,heap ptr = %p\n",&x,ptr);
        printf("Hello World\n");
        sleep(2);
    }
}
