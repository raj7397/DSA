#include <bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node {
    struct Node* left, *right;
    int key;
};
 
// Utility function to create a new
// tree Node
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
 
//Preorder traversal to store l or r in the string traversing
//from LCA to the given node key
void findPath(struct Node* root, int d,string str,string &s){
    if(root==NULL){
        return;
    }
     
    if(root->key==d){
        s=str;
        return;
    }
    findPath(root->left,d,str+"l",s);
    findPath(root->right,d,str+"r",s);
}
 
// Utility function to find the LCA of
// two given values n1 and n2.
struct Node* findLCAUtil(struct Node* root, int n1, int n2,bool&v1,bool&v2){
    // Base case
    if (root == NULL)
        return NULL;
 
    if (root->key == n1){
        v1=true;
        return root;
    }
    if(root->key == n2){
        v2=true;
        return root;
    }
    // Look for keys in left and right subtrees
    Node* left_lca = findLCAUtil(root->left, n1, n2,v1,v2);
    Node* right_lca = findLCAUtil(root->right, n1, n2,v1,v2);
    if (left_lca && right_lca){
        return root;
    }
    return (left_lca != NULL) ? left_lca : right_lca;
}
 
bool find(Node* root, int x){
    if(root==NULL){
        return false;
    }
    if((root->key==x) || find(root->left,x) || find(root->right,x)){
        return true;
    }
    return false;
}
 
//Function should return LCA of two nodes if both nodes are
//present otherwise should return NULL
Node* findLCA(struct Node* root, int first, int second){
    bool v1=false;
    bool v2=false;
    Node* lca = findLCAUtil(root,first,second,v1,v2);
    if((v1&&v2) || (v1&&find(lca,second)) || (v2&&find(lca,first))){
        return lca;
    }
    return NULL;
}
   
 
// function should return the number of turns required to go from
//first node to second node
int NumberOFTurns(struct Node* root, int first, int second){
  // base cases if root is not present or both node values are same
    if(root==NULL || (first==second)){
        return 0;
    }
   
    string s1 ="";
    string s2 = "";
    Node* lca = findLCA(root,first,second);
 
    findPath(lca,first,"",s1);
    findPath(lca,second,"",s2);
    if(s1.length()==0 && s2.length()==0){
       return -1;
    }
    cout<<"s1: "<<s1<<endl;
    cout<<"s2: "<<s2<<endl;
    reverse(s1.begin(),s1.end());

    s1+=s2;
    cout<<"s1 concate: "<<s1<<endl;
 
    int cnt=0;
    bool flag=false;
    for(int i=0; i<(s1.length()-1); i++){
        cout<<"before comp: s1[i]: "<<s1[i]<<" s1[i+1]: "<<s1[i+1]<<endl;
        if(s1[i]!=s1[i+1]){
            flag=true;
            cnt+=1;
        }
    }
    if(!flag){
       return -1;
    }
    return cnt;
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree given in the above
    // example
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->right->left->left = newNode(9);
    root->right->left->right = newNode(10);
 
    int turn = 0;
    if ((turn = NumberOFTurns(root, 5, 10))!=-1)
        cout << turn << endl;
    else
        cout << "Not Possible" << endl;
 
    return 0;
}