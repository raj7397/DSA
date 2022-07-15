#include <stdio.h>
#include <string.h>
void printArray(int (*arr)[3],int n)
{
    for(int i = 0; i < n;i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int main(int argc, char ** argv)
{
    char arr[3][10];
    for(int i = 0; i < 3; i++)
    {
        scanf("%s",arr[i]);
    }
    char *(*ptr)[10] = arr;
    printf("printing: \n");
    for(int i = 0; i< 3;i++)
    {
        printf("%s\n",ptr[i]);
    }
 //   int arr[5][3];
    /*for(int i= 0; i < 5;i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arr[i][j] = (i + j);
        }
    }
    printArray(arr,5);*/
}