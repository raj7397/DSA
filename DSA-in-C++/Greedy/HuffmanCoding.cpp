#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
class Node{
    public:
     char data;
     int freq;
     Node *left;
     Node *right;
     Node(char data, int freq)
     {
         this->data= data;
         this->freq = freq;
         left = nullptr;
         right = nullptr;
     }
};
class pqComp{
    public:
        bool operator()(Node *a, Node *b)
        {
            if(a->freq > b->freq)
                return true;
            return false;
        }

};
void print_huffman_code(vector<char>&charArr, vector<int> &freq);

void print_code(Node * root,string str);
int main(int argc, char **argv)
{
    int n; 
    cin>>n;
    vector<char>charArr(n);
    vector<int>freq(n);
    for(int i = 0; i < n;i++)
    {
        cin>>charArr[i];
        cin>>freq[i];
    }
    //cout<<"printing array:"<<endl;
    /*for(int i = 0; i < n; i++)
    {
        cout<<charArr[i]<<" "<<freq[i]<<endl;
    }*/
    print_huffman_code(charArr,freq);
}
void print_huffman_code(vector<char> & charArr,vector<int> &freq)
{
    priority_queue<Node*,vector<Node*>,pqComp>pq;
    int n = charArr.size();
    for(int i = 0; i <n; i++)
    {
        pq.push(new Node(charArr[i],freq[i]));
    }
    while(pq.size() > 1)
    {
        Node * first = pq.top();
        pq.pop();
        Node * second = pq.top();
        pq.pop();
        Node * new_node = new Node('$', first->freq + second->freq);
        new_node->left = first;
        new_node->right = second;
        pq.push(new_node);
    }
    Node * root = pq.top();
    //cout<<" bofore code: "<<endl;
    print_code(root, "");
    //cout<<"after code: "<<endl;
}
void print_code(Node * root , string asf)
{
    //cout<<"root->data: "<<root->data<<" code: "<<asf<<endl;
    if(root == nullptr)
        return ;
    if(root->data != '$')
    {
        cout<<root->data<<" "<<asf<<endl;
        return;
    }   
    print_code(root->left, asf + "0");
    print_code(root->right, asf + "1");
}