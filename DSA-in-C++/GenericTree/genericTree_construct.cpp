#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Node{
    public:
         int data; 
        vector<Node *>children;
        Node(int data)
        {
            this->data = data;
            //children = new vector<int>;
        }
};
Node * constructGenericTree(vector<int> &);
void display(Node *node);

int main(int argc, char **argv)
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    Node *root = constructGenericTree(arr);
    display(root);
}
Node * constructGenericTree(vector<int> & arr)
{
    stack<Node*> st;
    Node * root = nullptr;
    for(int i =0; i < arr.size(); i++)
    {
        if(st.size() > 0 && arr[i] == -1)
        {
            st.pop();
        }
        else if(st.size() == 0)
        {
            Node * temp = new Node(arr[i]);
            root = temp;
            st.push(temp);
        }
        else{
            Node *temp = st.top();
            Node *new_node = new Node(arr[i]);
            (temp->children).push_back(new_node);
            st.push(new_node);
        }
      //  st.push()
    }
    return root;
}
void display(Node *node) 
{
   // cout<<"node->data: "<<node->data<<endl;
    string str = to_string(node->data) + " -> ";

    /*vector<Node*> tempRes = node->children;
    for(int i =0; i < tempRes.size(); i++)
    {
        Node * node = tempRes[i];
        str = str + to_string(node->data)+ ", ";
    }*/

    for (Node *child : node->children) {
      str += to_string(child->data) + ", ";
    }
    str += ".";
    //System.out.println(str);
    cout<<str<<endl;
 /*   for(int i =0; i < tempRes.size(); i++)
    {
        Node * node = tempRes[i];
        display(node);
        //str = str + node->data+ ", ";
    }*/
   for (Node *child : node->children) {
      display(child);
    }
  }