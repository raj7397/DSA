import java.util.concurrent.ThreadPoolExecutor.DiscardOldestPolicy;

public class AVLConstruction {
    public static class Node{
        int data;
        Node left;
        Node right;
        int ht; 
        int bal;
        Node()
        {

        }
        Node(int data)
        {
            this.data = data;
            ht = 1;
            bal = 0;
        }
        
    }
    public static Node construct()
    {
        int [] arr = {10,12,20,25,30,37,40,50,60,62,70,75,80,87,90};
        Node root = avlConstruct(arr,0,arr.length -1);
        return root;
    }
    public static Node avlConstruct(int [] arr,int low, int high)
    {
        if(low > high)
            return null;
        int mid = (low + high)/2;
        Node root = new Node(arr[mid]);
        root.left = avlConstruct(arr, low, mid - 1);
        root.right = avlConstruct(arr, mid + 1, high);
        root.ht = getHeight(root);
        root.bal = getBalance(root);
        return root;
    }
    public static void  display(Node root)
    {
        if(root == null)
            return;
        String str = "< "+root.data+" [ "+root.ht+","+root.bal+"]"+" >";
        String lstr = ".";
        String rstr = ".";
        if(root.left != null)
            lstr = ""+root.left.data;
        if(root.right != null)
            rstr = ""+root.right.data;
        System.out.println(lstr+str+rstr);
        display(root.left);
        display(root.right);

    }
    public static int getHeight(Node root)
    {
        int lh = (root.left == null)? 0: root.left.ht;
        int rh = (root.right == null) ? 0: root.right.ht;
        return Math.max(lh,rh) + 1;
    }
    public static int getBalance(Node root)
    {
        int lh = (root.left == null) ? 0: root.left.ht;
        int rh = (root.right == null) ? 0: root.right.ht;
        return (lh - rh);
    }
    public static void main(String[] args) {
        Node root = construct();
        display(root);
    }
    
}
