#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
//#include <priority_queue>
#include <unordered_map>
#include <climits>
using namespace std;
class Node {
public:
  int data;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data) {
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
class qTriplet{
public:
    Node * node;
    int h;
    int v;
    qTriplet(Node *node, int h, int v)
    {
        this->node = node;
        this->h = h;
        this->v = v;
    }

};
class myComp{
public:
    bool operator() (qTriplet a, qTriplet b)
    {
        if(a.v == b.v)
        {
            if(b.node->data < a.node->data)
                return true;
            return false;
        }
        else{
            if(b.v < a.v)
                return true;
            return false;
        }
    }
};
int idx = 0;
Node* constructTree(vector<int>& arr) {
  if (idx == arr.size() || arr[idx] == -1) {
    idx++;
    return nullptr;
  }
  Node* node = new Node(arr[idx++]);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

void display(Node* node) {
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


vector<vector<int>> verticalOrder(Node *root)
{
    vector<vector<int>>ans;
    if(root == nullptr)
        return ans;
    queue<qTriplet> q;
    q.push(qTriplet(root,0,1));
    int lh = 0;
    int rh = 0;
    unordered_map<int, priority_queue<qTriplet,vector<qTriplet>,myComp>> hm;
    while(q.size() > 0)
    {
        qTriplet remNode = q.front();
        q.pop();
        if(remNode.h < lh)
            lh = remNode.h;
        if(remNode.h > rh)
            rh = remNode.h;
        
        if(hm.find(remNode.h) == hm.end())
        {
            priority_queue<qTriplet, vector<qTriplet>,myComp>temp;
            hm.insert(make_pair(remNode.h,temp));
            hm[remNode.h].push(remNode);
        }
        else{
            hm[remNode.h].push(remNode);
        }
        if(remNode.node->left != nullptr)
        {
            q.push(qTriplet(remNode.node->left,remNode.h - 1, remNode.v + 1));
        }
        if(remNode.node->right != nullptr)
        {
            q.push(qTriplet(remNode.node->right, remNode.h + 1, remNode.v + 1));
        }
    }
    cout<<"lh: "<<lh<<" rh: "<<rh<<endl;
    for(int i = lh; i <= rh; i++)
    {
        vector<int>temp;
        auto pq = hm[i];
        while(pq.size() > 0)
        {
            auto  x = pq.top();
            pq.pop();
            temp.push_back(x.node->data);
        }
        ans.push_back(temp);
    }
    return ans;
}
void printVerticalOrder(Node *root)
{
 auto res=  verticalOrder(root);
 for(int i = 0; i< res.size();i++)
 {
     for(int j = 0; j < res[i].size();j++)
     {
         cout<<res[i][j]<<" ";
     }
     cout<<endl;
 }
}
vector<vector<int>> diagonalOrder(Node *root)
{
    vector<vector<int>> ans;
    if(root == nullptr)
        return ans;
    queue<Node *> q;
    q.push(root);
    while(q.size() > 0)
    {
        int size = q.size();
        vector<int>tempRes;
        for(int i = 0; i < size; i++)
        {
            auto currNode = q.front();
            q.pop();
            while(currNode != nullptr)
            {
                tempRes.push_back(currNode->data);
                if(currNode->left != nullptr)
                    q.push(currNode->left);
                currNode = currNode->right;
            }
            
        }
        ans.push_back(tempRes);
    }
    return ans;
}
void printDiagonalOrder(Node *root)
{
    auto res = diagonalOrder(root);
 for(int i = 0; i< res.size();i++)
 {
     for(int j = 0; j < res[i].size();j++)
     {
         cout<<res[i][j]<<" ";
     }
     cout<<endl;
 }
}
void diagonalOrderUsingRecursion(Node *root,int diag,unordered_map<int,vector<int>>&hm,int &maxD)
{
    if(root == nullptr)
        return;
    if(diag > maxD)
        maxD = diag;

    if(hm.find(diag) == hm.end())
    {
        vector<int>v;
        hm.insert(make_pair(diag,v));
        hm[diag].push_back(root->data);
    }
    else{
        hm[diag].push_back(root->data);
    }
    diagonalOrderUsingRecursion(root->left, diag + 1, hm, maxD);
    diagonalOrderUsingRecursion(root->right,diag , hm, maxD);
}
void printDiagonalUsingRecursion(Node *root)
{
    unordered_map<int,vector<int>>hm;
    int maxD = 0;
    diagonalOrderUsingRecursion(root, 0,hm,maxD);
    for(int i = 0; i <= maxD; i++)
    {
        for(int j = 0; j < hm[i].size(); j++)
        {
            cout<<hm[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
void leftWallTraversal(Node *root, vector<int> &ans)
{
    if(root == nullptr)
        return;
    if(root->left != nullptr || root->right != nullptr)
        ans.push_back(root->data);
    if(root->left != nullptr)
    {
        leftWallTraversal(root->left, ans);
    }
    else if(root->right != nullptr)
    {
        leftWallTraversal(root->right, ans);
    }
}
void rightWallTraversal(Node *root, vector<int> &ans)
{
    if(root == nullptr)
        return;
    if(root->right != nullptr)
    {
        rightWallTraversal(root->right, ans);
    }
    else if(root->left != nullptr)
    {
        rightWallTraversal(root->left,ans);
    }
    if(root->left != nullptr || root->right != nullptr)
    {
        ans.push_back(root->data);
    }
}
void leavesTraversal(Node *root, vector<int> &ans)
{
    if(root == nullptr)
        return;
    leavesTraversal(root->left, ans);
    if(root->left == nullptr && root->right == nullptr)
        ans.push_back(root->data);
    leavesTraversal(root->right, ans);
}
void printBoundaryTraversal(Node *root)
{
    vector<int>ans;
    if(root == nullptr)
        return ;
    ans.push_back(root->data);
    leftWallTraversal(root->left,ans);
    leavesTraversal(root->left, ans);
    leavesTraversal(root->right,ans);
    rightWallTraversal(root->right,ans);
    for(int i = 0; i < ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
int maxRootToLeaf(Node *root)
{
    if(root->left != nullptr && root->right != nullptr)
    {
        int left = maxRootToLeaf(root->left);
        int right = maxRootToLeaf(root->right);
        return max(left, right) + root->data;
    }
    else if(root->left != nullptr)
    {
        int left = maxRootToLeaf(root->left);
        return left + root->data;
    }
    else if(root->right != nullptr)
    {
        int right = maxRootToLeaf(root->right);
        return right + root->data;
    }
    else{
        return root->data;
    }
}
int maxRootToNode(Node *root)
{
    if(root->left != nullptr && root->right != nullptr)
    {
        int left = maxRootToLeaf(root->left);
        int right = maxRootToLeaf(root->right);
        return max(max(left, right),0) + root->data;
    }
    else if(root->left != nullptr)
    {
        int left = maxRootToLeaf(root->left);
        int left_dash = max(left, 0);
        return left_dash + root->data;
    }
    else if(root->right != nullptr)
    {
        int right = maxRootToLeaf(root->right);
        int right_dash = max(right, 0);
        return right_dash + root->data;
    }
    else{
        return root->data;
    }
}
int maxRootToNode2(Node *root)
{
    if(root == nullptr)
        return INT_MIN;
    if(root->left == nullptr && root->right == nullptr)
    {
        return root->data;
    }
    int leftAns = maxRootToNode2(root->left);
    int rightAns = maxRootToNode2(root->right);
    return max(max(leftAns,rightAns),0) + root->data;
}
int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    if (temp == "n") {
      arr[i] = -1;
    } else {
      arr[i] = stoi(temp);
    }
  }
  Node* root = constructTree(arr);
 // printBoundaryTraversal(root);
  cout<<"max root to Node method2: "<<maxRootToNode2(root)<<endl;
 // printDiagonalUsingRecursion(root);
  //display(root);
  //printVerticalOrder(root);
 // printDiagonalOrder(root);
 // levelOrder(root);
}