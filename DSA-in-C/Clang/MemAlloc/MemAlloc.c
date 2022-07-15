#include <stdio.h>
#include <string.h>
//#include <alloc.h>
#include <stdlib.h>

struct myData{

};
struct Stud{
    int roll;
    int class;
    char name[10];
};
int main(int argc, char ** argv)
{
    struct Stud myStud = {.class = 20,.roll = 14, .name ="Rajkalash"};
    struct Stud s1 = {class : 30, roll: 15,name: "Sita"};
    printf("roll: %d, class: %d , name: %s\n",myStud.roll,myStud.class,myStud.name);
    printf("roll: %d, class: %d , name: %s\n",s1.roll,s1.class,s1.name);
 /*   struct myData d;
    int * arr = (int *)malloc(4 * sizeof(int));
    for(int i = 0; i < 4;i++)
    {
        arr[i] = 10 * (i +1);
    }
    for(int i = 0; i < 4; i++)
    {
        printf("value: %d\n",arr[i]);
    }
    arr = (int *)realloc(arr, 2 * sizeof(int));
       printf("After realloc: \n");
       for(int i = 0; i < 10; i++)
    {
        printf("value: %d\n",arr[i]);
    }*/
}