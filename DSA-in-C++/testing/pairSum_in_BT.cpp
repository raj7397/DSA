#include <iostream>
#include <unordered_set>

using namespace std;
 
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
    int data;
    struct Node *left, *right;
};
 
//Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(node->left);
 
    // then recur on right subtree
    printPostorder(node->right);
 
    // now deal with the node
    cout << node->data << " ";
}
 
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout << node->data << " ";
 
    /* now recur on right child */
    printInorder(node->right);
}
 
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first print data of node */
    cout << node->data << " ";
 
    /* then recur on left subtree */
    printPreorder(node->left);
 
    /* now recur on right subtree */
    printPreorder(node->right);
}
 
 bool t2sumHelper2(struct Node * root, int sum, unordered_set<int>&s)
 {
     if(root == nullptr)
        return false;
    cout<<"root->data: "<<root->data<<endl;
    if(s.find(sum - root->data) != s.end())
    {
        cout<<"In find: "<<endl;
        return true;
    }
    bool la = t2sumHelper2(root->left, sum , s);
    if(la == true)
        return true;
    s.insert(root->data);
    return t2sumHelper2(root->right, sum, s);
 }
/* Driver program to test above functions*/
int main()
{
    struct Node* root = newNode(7);
    root->left = newNode(10);
    root->right = newNode(9);
    root->left->left = newNode(20);
   // root->left->right = newNode(5);
 
   unordered_set<int>s;
   cout<<"ans: "<<t2sumHelper2(root,19,s)<<endl;
    return 0;
}