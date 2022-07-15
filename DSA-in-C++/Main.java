import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        String str = scn.next();
        printEncodings(str, "");

    }

    public static void printEncodings(String str, String ans) {
        if(str.length() == 0)
        {
            System.out.println(ans);
            return;
        }
        if(str.charAt(0) == '0')
        {
            System.out.println("nothing");
            return ;
        }
        char ch = str.charAt(0);
        int d = ch + '0';
        d = d-1+'a';
        if(str.length() >= 1)
        {
            String ros = str.substring(1);
            char pChar = (char)d;
            if(d >= 1 && d <= 26)
            {
                printEncodings(ros, ans + pChar);
            }
        }
        if(str.length() >= 2)
            {
            String secStr = str.substring(2);
            int d2 = (secStr.charAt(0)+'0')*10 + secStr.charAt(1)+'0';
            d2 = d2-1+'a';
             ros = str.substring(2);
           pChar = (char)d2;
            if(d2 >= 1 && d2 <= 26)
            {
                printEncodings(ros, ans+pChar);
            }
        }
        
    }

}