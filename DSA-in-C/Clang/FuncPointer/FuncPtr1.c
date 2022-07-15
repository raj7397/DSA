#include <stdio.h>
#include <string.h>

int sum(int a,int b)
{
    return a+b;
}
typedef int(*calculate[3])(int,int);
typedef int(*funPtr)(int,int);
int sub(int a,int b, funPtr sumOfNum)
{
    int res3 = sumOfNum(a,b);
    printf("res3: %d\n",res3);
}
int sub2(int a,int b)
{
    return a-b;
}
int mult(int a,int b)
{
    return a*b;
}
int simplyfy(int a,int b,calculate cal)
{
    int sum = (*cal[0])(a,b);
    int sub = (*cal[1])(a,b);
    int mult = (*cal[2])(a,b);
    printf("sum: %d, sub: %d, mult: %d\n",sum,sub,mult);
}
int main(int argc, char **argv)
{
    int a = 200, b= 99;
    calculate cal ;
    cal[0] = sum;
    cal[1] = sub2;
    cal[2] = mult;
    simplyfy(a,b,cal);
 /*   int a = 10, b = 20;
    sub(a,b,sum);
    int(*fun_ptr)(int,int);
    fun_ptr = &sum;
    int result = fun_ptr(a,b);
    printf("result: %d\n",result);
    funPtr ptr1;
    ptr1 = &sum;
    int result2 = ptr1(33,33);
    printf("result: %d: \n",result2);*/
}