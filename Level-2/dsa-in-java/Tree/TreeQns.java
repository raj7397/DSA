import java.io.*;
import java.util.*;

public class TreeQns {
  private int hd;
  public static class Node {
    int data;
    Node left;
    Node right;

    Node(int data, Node left, Node right) {
      this.data = data;
      this.left = left;
      this.right = right;
    }
  }

  public static class Pair {
    Node node;
    int state;

    Pair(Node node, int state) {
      this.node = node;
      this.state = state;
    }
  }

  public static Node construct(Integer[] arr) {
    Node root = new Node(arr[0], null, null);
    Pair rtp = new Pair(root, 1);

    Stack<Pair> st = new Stack<>();
    st.push(rtp);

    int idx = 0;
    while (st.size() > 0) {
      Pair top = st.peek();
      if (top.state == 1) {
        idx++;
        if (arr[idx] != null) {
          top.node.left = new Node(arr[idx], null, null);
          Pair lp = new Pair(top.node.left, 1);
          st.push(lp);
        } else {
          top.node.left = null;
        }

        top.state++;
      } else if (top.state == 2) {
        idx++;
        if (arr[idx] != null) {
          top.node.right = new Node(arr[idx], null, null);
          Pair rp = new Pair(top.node.right, 1);
          st.push(rp);
        } else {
          top.node.right = null;
        }

        top.state++;
      } else {
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

  public static void levelOrder(Node node) {
      Queue<Node> q = new LinkedList<>();
      q.add(node);
      while(q.size() > 0)
      {
          Node temp = q.peek();
          q.remove();
          System.out.print(temp.data+ " ");
          if(temp.left != null)
            q.add(temp.left);
         if(temp.right != null)
            q.add(temp.right);
      }
      System.out.println();

    // write your code here
  }
  public static void levelOrderLW(Node node)
  {
      if(node == null)
        return;
    Queue<Node> q = new LinkedList<>();
    q.add(node);
    q.add(null);
    while(q.size() > 0)
    {
        Node temp = q.peek();
        q.remove();
        if(temp != null)
        {
            System.out.print(temp.data+" ");
            if(temp.left != null)
                q.add(temp.left);
            if(temp.right != null)
                q.add(temp.right);
        }
        else{
            if(q.size() > 0)
            {
                System.err.println();
                q.add(null);
            }
        }
    }
  }
  public  static List<List<Integer>> levelOrderBottom(Node root) 
 {
    List<List<Integer>> ans = new LinkedList<>();
    if(root == null)
        return ans;
    Queue<Node> q = new LinkedList<>();
    q.add(root);
    q.add(null);
    LinkedList<Integer> tempRes = new LinkedList<>();
    Stack<LinkedList> st = new Stack<>();
    while(q.size() > 0)
    {
        Node temp = q.peek();
        q.remove();
        if(temp != null)
        {
            tempRes.add(temp.data);
            //System.out.println("temp.data: "+temp.data);
            if(temp.left != null)
                q.add(temp.left);
            if(temp.right != null)
                q.add(temp.right);
        }
        else{
            st.push(tempRes);
            tempRes = new LinkedList<>();
            if(q.size() > 0)
                q.add(temp);
        }
    }
    while(st.size() > 0)
    {
        ans.add(st.peek());
        st.pop();
    }
    System.out.println(ans);
    return ans;
}
  public static class qPair{
    int hd;
    Node node;
    public qPair(int hd, Node node)
    {
      this.hd = hd;
      this.hd = hd;
      this.node = node;
    }
  }
  public static void topView(Node node)
  {
    if(node == null)
      return;
    int minHd = 0, maxHd = 0;
    HashMap<Integer, Integer> hm = new HashMap<>();
     //TreeMap<Integer, Integer> hm = new TreeMap<>();
     Queue<qPair> q = new LinkedList<>();
     q.add(new qPair(0, node));
     while(q.size() > 0)
     {
       qPair remPair = q.peek();
       if(remPair.hd < minHd)
          minHd = remPair.hd;
       if(remPair.hd > maxHd)
          maxHd = remPair.hd;
       q.remove();
       if(hm.containsKey(remPair.hd) == false)
       {
         hm.put(remPair.hd, remPair.node.data);
       }
       if(remPair.node.left != null)
       {
          q.add(new qPair(remPair.hd - 1, remPair.node.left));
       }
       if(remPair.node.right != null)
       {
         q.add(new qPair(remPair.hd + 1, remPair.node.right));
       }
     }
     for(Map.Entry<Integer,Integer> ele : hm.entrySet())
     {
       System.out.println("hd: "+ele.getKey()+ " value: "+ ele.getValue());
     }
     System.out.println("ordered value: ");
     for(int i = minHd; i <= maxHd; i++)
     {
       System.out.println("Key: "+i+ " value: "+hm.get(i));
     }
  }
 public static void reverseLevelOrder(Node node)
 {
     if(node == null)
        return ;
     Queue<Node> q = new LinkedList<>();
     Stack<String> s = new Stack<>();
     q.add(node);
     q.add(null);
     String res= "";
     while(q.size() > 0)
     {
         Node temp = q.peek();
         q.remove();
         if(temp != null)
         {
             res = res + temp.data +" ";
             if(temp.left != null)
                q.add(temp.left);
            if(temp.right != null)
                q.add(temp.right);

         }
         else{
             s.push(res);
             res = "";
             if(q.size() > 0)
             {
                 q.add(null);
             }
         }
     }
     while(s.size() > 0)
     {
         System.out.println(s.peek());
         s.pop();
     }
 }
 static class LOPair{
   Node node;
   int vl;
   LOPair(Node node, int vl)
   {
     this.node = node;
     this.vl = vl;
   }
 }
 public static  void levelOrderLineWiseUsingPair(Node node)
 {
   if(node == null)
      return;
    
   int cl = 1;
   Queue<LOPair> q = new LinkedList<>();
   q.add(new LOPair(node, 1));
   while(q.size() > 0)
   {
     LOPair remPair = q.peek();
     q.remove();
     if(remPair.vl > cl)
     {
       cl = remPair.vl;
       System.out.println();
     }
     System.out.print(remPair.node.data+" ");
     if(remPair.node.left != null)
     {
       q.add(new LOPair(remPair.node.left, remPair.vl + 1));
     }
     if(remPair.node.right != null)
     {
       q.add(new LOPair(remPair.node.right, remPair.vl + 1));
     }
   }

 }
 public static void morrisinOrderTraversal(Node root)
 {
   Node curr = root;
   while(curr != null)
   {
     if(curr.left == null)
     {
       System.out.print(curr.data+" ");
       curr= curr.right;
     }
     else {
       Node iop = curr.left;
       while(iop.right != null && iop.right != curr)
       {
         iop = iop.right;
       }
       if(iop.right == null)
       {
         iop.right = curr;
         curr = curr.left;
       }
       else {
         iop.right = null;
         System.out.print(curr.data+ " ");
         curr = curr.right;
       }
     }
   }
   System.out.println();
 }
 public static void morrisPreOrderTraversal(Node root)
 {
     Node curr = root;
     while(curr != null)
     {
       
       if(curr.left == null)
       {
        System.out.print(curr.data+" ");
         curr = curr.right;
       }
       else{
        
         Node iop = curr.left;
         while(iop.right != null && iop.right != curr) 
         {
           iop = iop.right;
         }
         if(iop.right == null)
         {
          System.out.print(curr.data+" ");
           iop.right = curr;
           curr = curr.left;
         }
         else{
           iop.right = null;
           curr = curr.right;
         }
        }
     }
     System.out.println();
 }
 public static int inorderSuccessor(Node root, int x)
 {
   Node curr = root;
    Node succ = null;
    boolean found = false;
    while(curr != null)
    {
      if(curr.left == null)
      {
        if(found == true)
        {
          succ =curr;
          return succ.data;
        }
        if(curr.data == x)
        {
          found = true;
        }
        curr = curr.right;
      }
      else{
        Node iop = curr.left;
        while(iop.right != null && iop.right != curr)
        {
          iop = iop.right;
        }
        if(iop.right == null)
        {
          iop.right = curr;
          curr = curr.left;
        }
        else{
          if(found == true)
          {
            succ = curr;
            return succ.data;
          }
          if(curr.data == x)
          {
            found = true;
          }
          iop.right = null;
          curr = curr.right;
        }
      }
    }
    return -1;
 }
 public static void iterativeTraversal(Node root)
 {
   String pre= "";
   String post = "";
   String in = "";
    Stack<Pair> st = new Stack<>();
    st.push(new Pair(root, 0));
    while(st.size() > 0)
    {
      Pair peekNode = st.peek();
      if(peekNode.state == 0)
      {
         pre+=peekNode.node.data+" ";
          if(peekNode.node.left != null)
          {
            st.push(new Pair(peekNode.node.left, 0));
          //  peekNode.state++;
          }
          peekNode.state++;
      }
      else if(peekNode.state == 1)
      {
        in+= peekNode.node.data+" ";
        if(peekNode.node.right != null)
        {
          st.push(new Pair(peekNode.node.right, 0));
         // peekNode.state++;
        }
        peekNode.state++;
      }
      else{
        post+= peekNode.node.data+" ";
        st.pop();
      }
    }
    System.out.println(pre);
    System.out.println(in);
    System.out.println(post);

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
    iterativeTraversal(root);
    //int x = 50;
    //morrisinOrderTraversal(root);
   // int res = inorderSuccessor(root,x);
    //System.out.println(res);
    //morrisPreOrderTraversal(root);
   // display(root);
 //   levelOrderLineWiseUsingPair(root);
    //topView(root);
    //System.out.println(levelOrderBottom(root));
    //levelOrder(root);
 //   levelOrderLW(root);
   // System.out.println("\nreverse Level order");
    //reverseLevelOrder(root);
  }

}