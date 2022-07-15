import java.util.*;
import java.io.*;

public class GenerateParenthesis{
    public static void main(String [] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        ArrayList<String> ans = generateParenthesis("(",1,0,n);
        System.out.println(ans);
    }
    public static ArrayList<String> generateParenthesis(String asf, int oc, int cc,int n)
    {
        if(asf.length() == 2*n)
        {
            ArrayList<String> base = new ArrayList<String>();
            base.add(asf);
            return base;
        }
        ArrayList<String> myAns = new ArrayList<String>();
        if(oc < n)
        {
            ArrayList<String> ans1 = generateParenthesis(asf+"(", oc + 1, cc,n);
            for(String ele: ans1)
            {
                myAns.add(ele);
            }
        }
        if(cc < oc)
        {
            ArrayList<String> ans2 = generateParenthesis(asf+")", oc, cc + 1, n);
            for(String ele: ans2)
            {
                myAns.add(ele);
            }
        }
        return myAns;

    }

}