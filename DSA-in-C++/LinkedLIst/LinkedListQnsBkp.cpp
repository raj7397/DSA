#include <iostream>
#include <string>

using namespace std;
void solve_mid_node();


class Node{
    public:
    int data;
    Node *next;
};
class LinkedList{
    public:
     Node *head;
     LinkedList()
     {
         head = nullptr;
     }
     Node * addBegin(Node * head,int val)
     {
         Node * temp = new Node();
         temp->data = val;
         temp->next = nullptr;
         if( head == nullptr)
         {
             return temp;
         }
         else {
             temp->next = head;
             head = temp;
         }
         return head;
     }
     void display(Node * head)
     {
         while(head != nullptr)
         {
             cout<<head->data<<" ";
             head = head->next;
         }
         cout<<endl;
     }
     int sizeOfList(Node * head)
     {
         int count = 0;
         while(head != nullptr)
         {
             count++;
             head = head->next;
         }
         return count;

     }
     int addTwoListHelper(Node * head1, int p1, Node *head2 ,int p2, Node* &head)
     {
         if(head1 == nullptr && head2 == nullptr)
         {
            return 0;
         }
         int carry = 0;
         int sum = 0;
         if(p1 > p2)
         {
            carry = addTwoListHelper(head1->next, p1-1, head2, p2,head);
            sum = head1->data + carry; 
         }
         else if(p2 > p1)
         {
             carry = addTwoListHelper(head1, p1, head2->next , p2-1, head);
             sum = head2->data + carry;
         }
         else{
             carry = addTwoListHelper(head1->next, p1-1, head2->next, p2-1, head);
             sum = head1->data + head2->data + carry;
         }
         int d = sum % 10;
         carry = sum/10;
         head = addBegin(head, d);
         return carry;

     }
     LinkedList * addTwoList(Node * head1, Node *head2)
     {
         LinkedList * ans = new LinkedList();
         int p1 = sizeOfList(head1);
         int p2 = sizeOfList(head2);
         int carry = addTwoListHelper(head1, p1,head2, p2,ans->head);
         if(carry > 0)
         {
             ans->head = addBegin(ans->head, carry);
         }
         return ans;
     }
     Node * mergeTwoSortedList(Node * head1, Node *head2)
     {
   /* if(head1 == NULL)
     {
         return head2;
     }
     else if(head2 == NULL)
     {
         return head1;
     }
     Node * head = NULL, *tail = NULL;
     while(head1 != NULL && head2 != NULL)
     {
         if(head1->data <= head2->data)
         {
             if(head == NULL)
             {
                 head = head1;
                 tail = head1;
             }
             else{
                 tail->next = head1;
                 tail = head1;
             }
             head1 = head1->next;
         }
         else{
             if(head == NULL)
             {
                 head = head2;
                 tail = head2;
             }
             else{
                 tail->next = head2;
                 tail = head2;
             }
             head2 = head2->next;
         }
     }
     if(head1 == NULL)
     {
         tail->next = head2;
     }
     else if(head2 == NULL)
     {
         tail->next = head1;
     }
     return head;*/
         if(head1 == nullptr)
            return head2;
        if(head2 == nullptr)
            return head1;
        Node * newHead = nullptr, *tail = nullptr;
        if(head1->data <= head2->data)
        {
            newHead = head1;
            tail = head1;
            head1 = head1->next;
        }
        else{
            newHead = head2;
            tail = head2;
            head2 = head2->next;
        }
        while(head1 != nullptr && head2 != nullptr)
        {
            if(head1->data <= head2->data)
            {
                tail->next = head1;
                tail = head1;
                head1 = head1->next;
            }
            else{
                tail->next = head2;
                tail = head2;
                head2 = head2->next;
            }
        }
        if(head1 == nullptr)
        {
            tail->next = head2;
        }
        else if(head2 == nullptr)
        {
            tail->next = head1;
        }
        return newHead;
        
     }

};

Node * mid_node(Node * );
void  solve_merge_sort();
Node * merge_sort(Node *head);

int main(int argc, char **argv)
{
    solve_merge_sort();
 //   solve_mid_node();

  //  cout<<"Second list: "<<endl;
 /*   LinkedList *list1 = new LinkedList();
    list1->head = list1->addBegin(list1->head, 15);
    list1->head = list1->addBegin(list1->head, 1);
    list1->display(list1->head);
    //LinkedList * ans = new LinkedList();
    
    //ans = list->addTwoList(list->head,list1->head);
    //cout<<"Ans display"<<endl;
  //  ans->display(ans->head);
   Node * mergeAns = list->mergeTwoSortedList(list->head, list1->head);
    LinkedList * mList = new LinkedList();
    cout<<"Displaying merged list: "<<endl;
    mList->head = mergeAns;
    mList->display(mList->head);
    solve_mid_node();
   // list->head = list->addBegin(list->head, 9);
    //list->head = list->addBegin(list->head, 9);*/
}
void solve_mid_node()
{
    LinkedList *list = new LinkedList();
    list->head = list->addBegin(list->head, 18);
    list->head = list->addBegin(list->head, 17);
    list->head = list->addBegin(list->head, 8);
    list->head = list->addBegin(list->head, 5);
    list->head = list->addBegin(list->head, 10);
    list->display(list->head);
    Node * mid = mid_node(list->head);
    cout<<"mid data: "<<mid->data<<endl;

}
Node * mid_node(Node * head)
{
    if(head == nullptr || head->next == nullptr)
        return head;
    
    Node *slow = head,*fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void solve_merge_sort()
{
   LinkedList *list = new LinkedList();
    list->head = list->addBegin(list->head, 1);
    list->head = list->addBegin(list->head, 1);
    list->head = list->addBegin(list->head, 4);
    list->head = list->addBegin(list->head, 2);
    list->head = list->addBegin(list->head, 2);
    list->display(list->head);
    list->head = merge_sort(list->head);
    cout<<"After merge sort: "<<endl;
    list->display(list->head);

}
Node * merge_sort(Node * head)
{
    if(head == nullptr || head->next == nullptr)
        return head;

    /*Node * mid = mid_node(head);
    Node *mNext = mid->next;
    mid->next = nullptr;*/
    Node * slow = head, *fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    Node *l1 = merge_sort(head);
    Node *l2 = merge_sort(fast);
    LinkedList * list = new LinkedList();
    Node * mNode = list->mergeTwoSortedList(l1,l2);
    return mNode;
}