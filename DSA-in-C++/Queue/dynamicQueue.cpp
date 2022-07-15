#include <iostream>
#include <exception>
using namespace std;

class DynamicQueue {
public:
  int* arr;
  int sizeQ;
  int front;
  int arrSize;

  DynamicQueue(int cap) {
   //   cout<<"contracut: "<<endl;
    sizeQ = 0;
    front = 0;
    arr = new int[cap];
    arrSize = cap;
  }

  int size() {
      return sizeQ;
    // write your code here
  }

  void add(int data) {
     // cout<<"in add"<<endl;
      if(sizeQ == arrSize)
      {
          int * temp = new int[2 * arrSize];
          for(int i = 0; i < sizeQ; i++)
          {
              int idx = (front + i) % arrSize;
              temp[i] = arr[idx];
          }
          front = 0;
          arrSize = 2 * arrSize;
          delete arr;
          arr = temp;
          add(data);
      }
      else{
       //   cout<<"in rear: "<<endl;
          int rear = (front + sizeQ) % arrSize;
          arr[rear] = data;
          sizeQ++;
      }
      //cout<<"Added in Queue"<<endl;
    // write your code here
  }

  int peek() {
      if(sizeQ == 0)
      {
          cout<<"Queue underflow"<<endl;
          return -1;
      }
      int d = arr[front];
      return d;
    // write your code here
  }

  int remove() {
      if(sizeQ == 0)
      {
          cout<<"Queue underflow" <<endl;
          return -1;
      }
      int d = arr[front];
      front = (front + 1) % arrSize;
      sizeQ--;
      return d;
    // write your code here
  }

  void display() {
      for(int i = 0; i < sizeQ; i++)
      {
          int idx = (i + front) % arrSize;
          cout<<arr[idx]<<" ";
      }
      //cout<<"after display: "<<endl;
      cout<<endl;
    // write your code here
  }
};

int main() {
 //int k;
 //cin>>k;
 //cout<<"k: "<<k<<endl;
  int n;
  cin >> n;
  //cout<<" n: "<<n<<endl;
  DynamicQueue q(n);
  string str;
  cin >> str;
    //cout<<"str: "<<str<<endl;
  while (str != "quit") {
    if (str == "add") {
      int val;
      cin >> val;
      //cout<<"Before add call:"<<endl;
      q.add(val);
      //cout<<"after add call: "<<endl;
    }
    else if (str == "remove") {
      int val = q.remove();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "peek") {
      int val = q.peek();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "size") {
      cout << q.size() << endl;
    }
    else if (str == "display") {
      q.display();
    }
    cin >> str;
  }
  return 0;
}




