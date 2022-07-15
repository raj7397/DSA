#include <stdio.h>
#include <string.h>
struct Stud{
    char add;
    int roll;
    char add2;
    int class;
    char name[10];
};
int sum(int a,int b);
int main(int arc, char ** argv)
{
    struct Stud s1;
    s1.roll = 200;
    s1.class = 12;
    strcpy(s1.name,"Rajkalash");
    printf("student size: %ld\n",sizeof(s1));
    printf("roll: %d class: %d, name %s\n",s1.roll,s1.class,s1.name);
    long int a;
    printf("size: %ld\n",sizeof(a));
    printf("size: %ld\n",sizeof(int));
    int (*func_ptr)(int,int) = NULL;
    func_ptr = &sum;
    printf("Ans: %d \n",func_ptr(10,20));
    printf("add: %d\n",(*func_ptr)(39,49));
}
int sum(int a, int b)
{
    return a+b;
}