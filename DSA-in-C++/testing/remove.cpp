// C++ program to remove all half nodes
//#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

struct node
{
	int data;
	struct node* left, *right;
};

struct node* newNode(int data)
{
	node* nod = new node();
	nod->data = data;
	nod->left = nod->right = NULL;
	return(nod);
}

void printInoder(struct node*root)
{
	if (root != NULL)
	{
		printInoder(root->left);
		cout<< root->data << " ";
		printInoder(root->right);
	}
}

// Removes all nodes with only one child and returns
// new root (note that root may change)
struct node* RemoveHalfNodes(struct node* root)
{
	if (root==NULL)
		return NULL;

	root->left = RemoveHalfNodes(root->left);
   //  root->left = solve(root->left);
  
   // root->right = solve(root->right);
   // return root;
	root->right = RemoveHalfNodes(root->right);
      if(root->left == nullptr && root->right != nullptr)
    {
        struct node *temp = root->right;
        delete root;
        return temp;

        //return root->right;
    }
    if(root->right == nullptr && root->left != nullptr)
    {
        struct node *temp = root->left ;
        delete root;
        return temp;
        //return root->left;
    }

	
	/*if (root->left==NULL)
	{
		struct node *new_root = root->right;
		free(root); // To avoid memory leak
		return new_root;
	}*/


	/* if current nodes is a half node with right
	child NULL right, then it's right child is
	returned and replaces it in the given tree */
	/*if (root->right==NULL)
	{
		struct node *new_root = root->left;
		free(root); // To avoid memory leak
		return new_root;
	}*/

	return root;
}

// Driver program
int main(void)
{
	struct node*NewRoot=NULL;
	struct node *root = newNode(2);
	root->left	 = newNode(7);
	root->right	 = newNode(5);
	root->left->right = newNode(6);
	root->left->right->left=newNode(1);
	root->left->right->right=newNode(11);
	root->right->right=newNode(9);
	root->right->right->left=newNode(4);

	cout<<"Inorder traversal of given tree \n";
	printInoder(root);

	NewRoot = RemoveHalfNodes(root);

	cout<<"\nInorder traversal of the modified tree \n";
	printInoder(NewRoot);
	return 0;
}
