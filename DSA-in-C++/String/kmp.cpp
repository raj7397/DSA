#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> kmp(string, string);
void fill_lps(int lps[], string );
int main(int argc, char ** argv)
{
    string text,pattern;
    cin>>text>>pattern;
    kmp(text,pattern);
}
vector<int> kmp(string text, string pat)
{
             int m = pat.length();
           // vector<int>lps(m);
           int lps[m];
            fill_lps(lps,pat);
            cout<<"lps array: "<<endl;
            for(int i = 0; i < m;i++)
            {
                cout<<lps[i]<<" ";
            }
            cout<<endl;
            int i = 0, j =0;
            vector<int>ans;
            int n = text.length();
            while(i < n)
            {
                if(text[i] == pat[j])
                {
                    i++;
                    j++;
                }
                if(j == m)
                {
                    ans.push_back(i - j + 1);
                    cout<<"i - j: "<<i -j <<endl;
                    j = lps[j - 1];
                }
                else if(i < n && text[i] != pat[j])
                {
                    if(j == 0)
                    {
                        i++;
                    }
                    else{
                        j = lps[j - 1];
                    }
                }
                   
            }
            return ans;
}
void fill_lps(int  lps[], string pat)
{
              int n = pat.length();
            int len = 0;
            int i = 1;
            lps[0] = 0;
            cout<<"pattern:"<<pat<<endl;
            while(i < n)
            {
                if(pat[i] == pat[len])
                {
                    len++;
                    i++;
                    lps[i] = len;
                    cout<<"i: "<<i<<"lps[i]: "<<lps[i]<<endl;
                }
                else{
                    if(len == 0)
                    {
                        lps[i] = len;
                        i++;
                    }
                    else{
                        len = lps[len - 1];
                    }
                }
            }
            cout<<"printing lps in fill"<<endl;
            for(int i = 0; i < n;i++)
                cout<<lps[i]<<" ";
            cout<<endl;
}