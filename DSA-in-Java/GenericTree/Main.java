import java.io.*;
import java.util.*;

public class Main {
  private static class Node {
    int data;
    ArrayList<Node> children = new ArrayList<>();
  }

  public static void display(Node node) {
    String str = node.data + " -> ";
    for (Node child : node.children) {
      str += child.data + ", ";
    }
    str += ".";
    System.out.println(str);

    for (Node child : node.children) {
      display(child);
    }
  }

  public static Node construct(int[] arr) {
    Node root = null;
    Stack<Node> st = new Stack<>();

    for(int i = 0; i < arr.length;i++)
    {
      if(arr[i] == -1)
      {
        st.pop();
      }
      else{
        Node temp = new Node();
        temp.data = arr[i];
        if(st.size() > 0)
        {
          st.peek().children.add(temp);
        }
        else{
          root = temp;
        }
        st.push(temp);
      }
    }


    return root;
  
  }

  //public static int size(Node node){
    // write your code here
  //}

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    int[] arr = new int[n];
    String[] values = br.readLine().split(" ");
    for (int i = 0; i < n; i++) {
      arr[i] = Integer.parseInt(values[i]);
    }

    Node root = construct(arr);
   // int sz = size(root);
    //System.out.println(sz);
     display(root);
  }

}