#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*void changeVal(int a,int *b)
{
    void * ptr = malloc(sizeof(int));
    memcpy(ptr,&a,sizeof(int));
    memcpy(b,ptr,sizeof(int));
}*/
struct Node{
    void * data;
    struct Node *next;
};
struct LinkedList{
    struct Node * head;
    struct Node *tail;
    //void (*funptrAdd)(void *);
    struct Node * (*funptrAddLast)(struct Node *,void *);
    void (*funptrPrintList)(struct Node * ,int);
};
struct Node * addLast(struct Node * head,void * data) 
{
    struct Node *curr = head;
    if(curr == NULL)
    {
        struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = (void *)malloc(sizeof(data));
        memcpy(newNode->data,data,sizeof(x));
       // printf("Added:\n");
        return newNode;
    }
    else{
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = malloc(sizeof(data));
        memcpy(newNode->data,data,sizeof(x));
        curr->next = newNode;
        newNode->next = NULL;
    }
    //printf("Added:\n");
    return head;
}
void printList(struct Node * head,void * data)
{
    while(head != NULL)
    {
      //  printf("Hi\n");
        memcpy(d,head->data,sizeof(d));
        printf("data: %lf \n",d);
        head = head->next;
    }
}
int main(int argc, char ** argv)
{
    struct LinkedList * list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->tail == NULL;
    //list->funptrAddFirst = NULL:
    list->funptrPrintList = &printList;
    list->funptrAddLast = &addLast;
    double a;
    list->head = list->funptrAddLast(list->head,20.99);
    list->head = list->funptrAddLast(list->head,10.88);
    list->head = list->funptrAddLast(list->head,22.77);
    list->head = list->funptrAddLast(list->head,43.87);
    list->head = list->funptrAddLast(list->head,32.22);
    list->funptrPrintList(list->head,a);



   /* int b;
    int a = 10;
    changeVal(a,&b);
    printf("b: %d\n",b);*/
}