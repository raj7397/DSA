#include <stdio.h>
#include <stdlib.h>

struct Size{
    char a:1;
    char b:1;
    char c: 1;
    char d:1;
    char e:1;
    char f:1;
    char g:1;
    char h:1;
    //int a:1;
    //int b:2;
    //int c:3;
};
int main(int argc, char ** argv)
{
    struct Size * ptr;
   struct Size s[1024]; 
  // ptr = &s[0];
   printf("size: %ld",sizeof(s));
  // printf("%d: ",&s[0].a);
  /*  int sSize = sizeof(s[0]);
    struct Size*ptr = &s[0];
    struct Size *ptr1 = &s[1];
    int bsize = (char*)ptr1 - (char*)ptr;
    printf("firsr: %d second: %d",sSize, bsize);*/

}