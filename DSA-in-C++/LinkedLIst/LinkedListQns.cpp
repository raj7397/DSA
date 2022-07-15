#include <iostream>
#include <string>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode * next;
    ListNode(int d)
    {
        val = d;
        next = nullptr;
    }

};
void solve_insert_at_begin();
ListNode * insert_at_begin(ListNode *head , int val);
void display(ListNode * );
void solve_insert_at_end();
ListNode * insert_at_end(ListNode *head, ListNode *& tail, int val);
void solve_add_two_list();
ListNode * add_two_list(ListNode *head1, ListNode *head2);
int add_two_list_helper(ListNode *, ListNode *,int,int,ListNode *&);
int sizeOfList(ListNode *);
ListNode* reverseBetween(ListNode* A, int B, int C) {
    ListNode *curr = A;
    if(curr == NULL || curr->next == NULL)  
        return curr;
    B = B-1;
    C = C-1;
    cout<<"C: "<<C<<endl;
    ListNode *prev1 = NULL;
    ListNode *c1 = curr, *c2 = curr;
    for(int i = 0; i < B; i++)
    {
        prev1 = c1;
        c1 = c1->next;
    }
    for(int i = 0; i < C; i++)
    {
        c2 = c2->next;
    }
    ListNode * last = c2->next;
   
    ListNode * curr1 = c1,*prev = NULL, *next = NULL;    
    ListNode *temp = c1;
    while(temp != NULL && temp != last)
   {
       ListNode * next = temp->next;
       temp->next = prev;
       prev = temp;
       temp = next;
   }
    if(prev1 == NULL)
    {
        prev1 = prev;
        c1->next = last;
        return prev1;
    }
    else{
        prev1->next = prev;
        c1->next = last;
        return curr;
    }
  //  prev1->next = prev;
    //c1->next = c2->next;
//    return curr;
}
void solve_reverse_between_node()
{
    int n,val;
    cin>>n;
    ListNode *head = NULL, *tail = nullptr;
    while(n > 0)
    {
        cin>>val;
        head = insert_at_end(head, tail,val);
        n--;
    }
    display(head);
    int A,B;
    cin>>A>>B;
    ListNode *ans = reverseBetween(head, A, B);
    cout<<"\nAfter reverse: "<<endl;
    display(ans);
//    ListNode * head = NULL, *tail = NULL;

}

int main(int argc, char ** argv)
{
    solve_reverse_between_node();
    //solve_add_two_list();
    //solve_insert_at_end();
   // solve_insert_at_begin();
}

int add_two_list_helper(ListNode *head1, ListNode *head2, int pv1, int pv2, ListNode *&ans)
{
    if(pv1 ==0 && pv2 ==0 )
    {
        return 0;
    }
    int sum = 0,c = 0;
    if(pv1 > pv2)
    {
         c = add_two_list_helper(head1->next,head2,pv1-1 , pv2,ans);
         sum = head1->val + c;
    }
    else if(pv2 > pv1)
    {
         c = add_two_list_helper(head1,head2->next, pv1, pv2-1, ans);
         sum = head2->val + c;
    }
    else{
         c = add_two_list_helper(head1->next, head2->next, pv1-1,pv2-1,ans);
         sum = head1->val + head2->val + c;
    }
    int d = sum % 10;
    ans = insert_at_begin(ans, d);
    c = sum / 10;
    return c;

}
ListNode * add_two_list(ListNode * head1, ListNode *head2)
{
    ListNode *ans = NULL;
    int pv1 = sizeOfList(head1);
    int pv2 = sizeOfList(head2);
    int carry = add_two_list_helper(head1, head2,pv1,pv2,ans);
    if(carry > 0)
    {
        ans = insert_at_begin(ans,carry);
    }
    return ans;
}
void solve_add_two_list()
{
    int n,m;
    cin>>n>>m;
    int val;
    ListNode *head1 = NULL, *head2 = nullptr,*tail1 = nullptr, *tail2 = nullptr;
    while(n > 0){
        cin>>val;
        head1 = insert_at_end(head1, tail1,val);
        n--;
    
    }
    while(m > 0)
    {
        cin>>val;
        head2 = insert_at_end(head2, tail2, val);
        m--;
    }
    cout<<"List-1: "<<endl;
    display(head1);
    cout<<"\nList-2"<<endl;
    display(head2);
    ListNode * ans = add_two_list(head1, head2);
    cout<<"\nans "<<endl;
    display(ans);

}
void solve_insert_at_end()
{
    int n,val;
    cin>>n;
    ListNode *head = NULL, *tail = nullptr;
    while(n > 0)
    {
        cin>>val;
        head = insert_at_end(head, tail,val);
        n--;
    }
    display(head);
}
void solve_insert_at_begin()
{
    int n , val; 
    cin>>n;
    ListNode * head = nullptr;

    while(n >0 )
    {
        cin>>val;
        head = insert_at_begin(head, val);
        n--;
    }
}
ListNode * insert_at_begin(ListNode * head, int val)
{
    ListNode * newNode = new ListNode(val);

    if(head == nullptr)
    {
        head = newNode;
        return head;    
    }
    else{
        newNode->next = head;
        head = newNode;
        return head;
    }
}
void display(ListNode * head)
{
    while(head != nullptr)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
}
int sizeOfList(ListNode * head)
{
    int count = 0;
    while(head != nullptr)
    {
        count++;
        head = head->next;
    }
    return count;
}
ListNode * insert_at_end(ListNode *head, ListNode * &tail, int val)
{
    ListNode *newNode = new ListNode(val);
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return head;
    }
    else{
        tail->next = newNode;
        tail = newNode;
        return head;
    }
}