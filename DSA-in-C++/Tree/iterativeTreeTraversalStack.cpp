#include<iostream>
#include<climits>
#include<string.h>
#include<vector>
#include <stack>
using namespace std;

// structure of node
class Node
{
public:
  int data;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data)
  {
    this->data = data;
  }
};

class Pair {
public:
  Node* node = nullptr;
  int state = 0;

  Pair(Node* node, int state) {
    this->node = node;
    this->state = state;
  }
};

int idx = 0;
Node* constructTree(vector<int>& arr)
{

  if (idx == arr.size() || arr[idx] == -1)
  {
    idx++;
    return nullptr;
  }
  Node* node = new Node(arr[idx++]);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

void display(Node* node)
{
  if (node == nullptr)
    return;
  string str = "";
  str += node->left != nullptr ? to_string(node->left->data) : ".";
  str += " <- " + to_string(node->data) + " -> ";
  str += node->right != nullptr ? to_string(node->right->data) : ".";
  cout << str << endl;

  display(node->left);
  display(node->right);
}

void iterativeTraversal(Node *root)
{
    if(root == nullptr)
        return;
    stack<Pair *> st;
    st.push(new Pair(root, 1));
    string pre = "";
    string post = "";
    string in = "";
    while(st.size() > 0)
    {
        Pair *topPair = st.top();
        if(topPair->state == 1)
        {
            pre = pre + to_string(topPair->node->data)+" ";
            topPair->state++;
            if(topPair->node->left != nullptr)
            {
                st.push(new Pair(topPair->node->left,1));
            }
        }
        else if(topPair->state == 2){
            in = in+to_string(topPair->node->data)+" ";
            topPair->state++;
            if(topPair->node->right != nullptr)
            {
                st.push(new Pair(topPair->node->right,1));
            }

        }
        else{
            post = post+to_string(topPair->node->data)+" ";
        }
    }
    cout<<"pre: "<<pre<<endl;
    cout<<"ind: "<<in<<endl;
    cout<<"post: "<<post<<endl;
}


int main()
{

  int n;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    if (temp == "n")
    {
      arr[i] = -1;
    }
    else
    {
      arr[i] = stoi(temp);
    }
  }

  Node* root = constructTree(arr);
  iterativeTraversal(root);

 /* int sz = size(root);
  int sm = sum(root);
  int max = maximum(root);
  int ht = height(root);
  cout << sz << endl;
  cout << sm << endl;
  cout << max << endl;
  cout << ht << endl;*/
}