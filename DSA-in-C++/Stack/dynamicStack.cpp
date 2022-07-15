#include <iostream>
#include <exception>
using namespace std;

class Stack {

public:
  int* arr;
  int tos;
  int MaxCapacity;

public:
  Stack(int size) {
    this->MaxCapacity = size;
    this->arr = new int[this->MaxCapacity];
    this->tos = -1;
  }



public:
  int size() {
      return tos + 1;
    // write your code here
  }

public:
  void push(int data) {
      if(tos == MaxCapacity - 1)
      {
          int *temp = new int[2 * MaxCapacity];
          for(int i = 0; i < MaxCapacity; i++)
          {
              temp[i] = arr[i];
          }
          tos = MaxCapacity -1 ;
          MaxCapacity = 2 * MaxCapacity;
          delete arr;
          arr = temp;
          push(data);
      }
      else{
          tos = tos + 1;
          arr[tos] = data;
      }

    // write your code here
  }

public:
  int top()
  {
      if(tos == -1)
      {
          cout<<"Stack underflow";
          return -1;
      }
     return arr[tos];
      
    // write your code here
  }

public:
  int pop()
  {
      if(tos == -1)
      {
          cout<<"Stack underflow"<<endl;
          return -1;
      }
      int d = arr[tos];
      tos--;
      return d;
    // write your code here
  }

public:
  void display() {
      int top = tos;
      while(top >= 0)
      {
          cout<<arr[i]<<" ";
          top--;
      }
      cout<<endl;
    // write your code here
  }
};

int main() {
  int n;
  cin >> n;
  Stack st(n);
  string str;
  cin >> str;

  while (str != "quit") {
    if (str == "push") {
      int val;
      cin >> val;
      st.push(val);
    } else if (str == "pop") {
      int val = st.pop();
      if (val != -1) {
        cout << val << endl;
      }
    } else if (str == "top") {
      int val = st.top();
      if (val != -1) {
        cout << val << endl;
      }

    } else if (str == "size") {
      cout << st.size() << endl;
    } else if (str == "display") {
      st.display();
    }
    cin >> str;
  }
}