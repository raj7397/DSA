import java.io.*;
import java.util.*;

public class Main{
  

public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String exp = br.readLine();
    printPostfixPrefix(exp);

    // code
 }
 public static int precedence(char ch)
 {
     if(ch == '1' || ch == '2')
        return 1;
    return 2;
 }
 public static void printPostfixPrefix(String exp)
 {
     Stack<String> postfixExp = new Stack<>();
     Stack<String> prefixExp = new Stack<>();
     Stack<Character> operator = new Stack<>();
     
     for(int i = 0; i < exp.length(); i++)
     {
         char ch = exp.charAt(i);
         if(ch == '(')
         {
             operator.push(ch);
         }
         else if(ch == ')')
         {
             while(operator.size() !=0 && operator.peek() != '(')
             {
                 char v3 = operator.peek();
                 operator.pop();
                 String postv2 = postfixExp.peek();
                 postfixExp.pop();
                 String postv1 = postfixExp.peek();
                 postfixExp.pop();
                 String res1 = postv1 + postv2 + v3;
                 postfixExp.push(res1);
                 String prev2 = prefixExp.peek();
                 prefixExp.pop();
                 String prev1 = prefixExp.peek();
                 prefixExp.pop();
                 String res2 = v3 + prev1 + prev2 ;
                 prefixExp.push(res2);
                 
             }
             operator.pop();
             
         }
         else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
         {
             while(operator.size() != 0 && operator.peek() != '(' && precedence(ch) <= precedence(operator.peek()))
             {
                 char v3 = operator.peek();
                 operator.pop();
                 String postv2 = postfixExp.peek();
                 postfixExp.pop();
                 String postv1 = postfixExp.peek();
                 postfixExp.pop();
                 String res1 = postv1 + postv2 + v3;
                 postfixExp.push(res1);
                 String prev2 = prefixExp.peek();
                 prefixExp.pop();
                 String prev1 = prefixExp.peek();
                 prefixExp.pop();
                 String res2 = v3 + prev1 + prev2;
                 prefixExp.push(res2);
                 
             }
             operator.push(ch);
         }
         else{
             String temp = "";
             temp = temp+ch;
             postfixExp.push(temp);
             prefixExp.push(temp);
         }
     }
     while(operator.size() != 0)
     {
                char v3 = operator.peek();
                 operator.pop();
                 String postv2 = postfixExp.peek();
                 postfixExp.pop();
                 String postv1 = postfixExp.peek();
                 postfixExp.pop();
                 String res1 = postv1 + postv2 + v3;
                 postfixExp.push(res1);
                 String prev2 = prefixExp.peek();
                 prefixExp.pop();
                 String prev1 = prefixExp.peek();
                 prefixExp.pop();
                 String res2 = v3 + prev1 + prev2;
                 prefixExp.push(res2);
         
     }
     System.out.println(postfixExp.peek());
     System.out.println(prefixExp.peek());
 }
}