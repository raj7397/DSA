#include <iostream>
#include <string>

using namespace std;
void swap(string &str, int i, int j)
{
    char t = str[i];
    str[i] = str[j];
    str[j] = t;
    cout<<"In swap: "<<str<<endl;
}
bool getPermutationHelper(string &str, int idx, int k, int &count, string &ans)
{
    if(idx == str.length())
    {
        cout<<"base case: "<<str<<endl;
        count++;
        if(count == k)
        {
            ans = str;
            return true;
        }
        else {
            return false;
        }
    }
        for(int i = idx; i < str.length(); i++)
        {
            swap(str,idx, i);
            cout<<"after swap and before call "<<str<<endl;
            if(getPermutationHelper(str, idx + 1 , k, count,ans) == true)
                return true;
            swap(str,idx,i);
            cout<<"after after return f "<<str<<endl;
        }
        return false;
    

}

string getPermutation(int A, int B) {
    string ans;
    string str = "";
    for(int i = 1; i <= A; i++)
    {
        str = str + to_string(i);
    }
    cout<<"Before call: "<<str<<endl;
    int count = 0;
    bool p = getPermutationHelper(str, 0, B,count, ans);
    return ans;
}
int main(int argc, char ** argv)
{
    int A = 3,B=5;
    cout<<"ans "<<getPermutation(A,B)<<endl;
}
