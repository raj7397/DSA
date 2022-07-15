import java.io.*;
import java.util.*;

public class TreeConstruction2 {
  public static class Node {
    int data;
    Node left;
    Node right;

    Node(int data, Node left, Node right) {
      this.data = data;
      this.left = left;
      this.right = right;
    }
    Node(int data)
    {
        this.data = data;
        this.left = null;
        this.right = null;
    }
  }

  public static class Pair {
     Node node;
     int state;
     Pair(Node node, int state)
     {
         this.node = node;
         this.state = state;
     }
  }

  public static Node construct(Integer[] arr) {
    Node root = new Node(arr[0]);
    Stack<Pair> st = new Stack<>();
    st.push(new Pair(root, 1));
    int idx = 1;
    while(st.size() > 0)
    {
        Pair peekPair = st.peek();
        if(peekPair.state == 1)
        {
            peekPair.state++;
            if(arr[idx] != null)
            {
                Node temp = new Node(arr[idx]);
                peekPair.node.left = temp;
                st.push(new Pair(temp, 1));
            }
            else{
                peekPair.node.left = null;
            }
            idx++;
        }
        else if(peekPair.state == 2)
        {
            peekPair.state++;
            if(arr[idx] != null)
            {
                Node temp = new Node(arr[idx]);
                peekPair.node.right = temp;
                st.push(new Pair(temp, 1));
            }
            else{
                peekPair.node.right = null;
            }
            idx++;
        }
        else{
            st.pop();
        }
    }
    return root;
  }

  public static void display(Node node) {
    if (node == null) {
      return;
    }

    String str = "";
    str += node.left == null ? "." : node.left.data + "";
    str += " <- " + node.data + " -> ";
    str += node.right == null ? "." : node.right.data + "";
    System.out.println(str);

    display(node.left);
    display(node.right);
  }
  public static void preOrder(Node node)
  {
      if(node == null)
        return;
      System.out.print(node.data+" ");
      preOrder(node.left);
      preOrder(node.right);
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    Integer[] arr = new Integer[n];
    String[] values = br.readLine().split(" ");
    for (int i = 0; i < n; i++) {
      if (values[i].equals("n") == false) {
        arr[i] = Integer.parseInt(values[i]);
      } else {
        arr[i] = null;
      }
    }

    Node root = construct(arr);
    preOrder(root);
    
  }

}