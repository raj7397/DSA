import java.util.*;
import java.io.*;

public class TreeConstruction{
    public static class sPair{
        TreeNode node;
        int state;
        public sPair(TreeNode node, int state)
        {
            this.node = node;
            this.state = state;
        }
    }
    /*public static class pair{
        TreeNode node;
        int state;
        public pair(TreeNode node, int state)
        {
            this.node = node;
            this.state = state;
        }
    }*/
    /*public static class pair{
        TreeNode node;
        int state;
        pair(TreeNode node,int state)
        {
            this.node = node;
            this.state = state;
        }
    }*/
    /*public static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int val)
        {
            this.val = val;
            this.left = null;
            this.right = null;
        }
    }*/
    
    public static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        public TreeNode(int v)
        {
            this.val = v;
            this.left = null;
            this.right = null;
        }

    }
    public static void display(TreeNode root)
    {
        if(root == null)
            return;
        System.out.println("root.val->" + root.val);
        display(root.left);
        display(root.right);
    }
    public static void preOrder(TreeNode root)
    {
        if(root == null)
            return;
        System.out.println(root.val);
        preOrder(root.left);
        preOrder(root.right);
    }
    public static void inOrder(TreeNode root)
    {
        if(root == null)
            return;
        inOrder(root.left);
        System.out.println(root.val);
        inOrder(root.right);
    }
    public static void postOrder(TreeNode root)
    {
        if(root == null)
            return;
        postOrder(root.left);
        postOrder(root.right);
        System.out.println(root.val);
    }
    public static void main(String [] args)
    {
       Integer [] arr = {50,25,12,null, null, 37,30,null,null,null,75,62,null,70,null,null,81,null,null};
       TreeNode root = constructTree(arr); 

      display(root);
    /*   System.out.println("preOrder");
       preOrder(root);
       System.out.println("inOrder");
       inOrder(root);
       System.out.println("postOrder");
       postOrder(root);*/
    }
    public static TreeNode constructTree(Integer [] arr)
    {

        TreeNode  root = new TreeNode(arr[0]);
        int idx = 1;
        Stack<sPair> st =new Stack<>();
        st.push(new sPair(root,1));
        while(st.size() > 0)
        {
            sPair peekEle = st.peek();
            if(peekEle.state == 1)
            {
                if(arr[idx] != null)
                {
                    TreeNode temp = new TreeNode(arr[idx]);
                    peekEle.node.left = temp;
                   // idx++;
                    st.push(new sPair(temp, 1));
                }
                idx++;
                //st.push(new sPair(arr[idx], 1));
                peekEle.state++;
            }
            else if(peekEle.state == 2)
            {
                if(arr[idx] != null)
                {
                    TreeNode temp = new TreeNode(arr[idx]);
                    peekEle.node.right = temp;
                    //idx++;
                    st.push(new sPair(temp, 1));
                }
                idx++;
                peekEle.state++;
            }
            else{
                st.pop();
 //               idx++;
            }
        }
        return root;
    }


      /*  TreeNode root = new TreeNode(arr[0]);
        Stack<pair> st = new Stack<pair>();
        st.push(new pair(root,1));
        int idx = 1;
        while(st.size() > 0)
        {
            pair pEle = st.peek();
            if(pEle.state == 1)
            {
                pEle.state++;
                if(arr[idx] != null)
                {
                    TreeNode temp = new TreeNode(arr[idx]);
                    pEle.node.left = temp;
                    st.push(new pair(temp,1));
                }
                idx++;
            }
            else if(pEle.state == 2){
                pEle.state++;
                if(arr[idx] != null)
                {
                    TreeNode temp = new TreeNode(arr[idx]);
                    pEle.node.right = temp;
                    st.push(new pair(temp, 1));
                }
                idx++;

            }
            else{
                st.pop();
            }
        }
        return root;
    }*/
    
}