#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solve(int A, int B, int C) {
        vector<int>palin;
    for(int i =  A; i <= B; i++)
    {
        int rev = 0;
        int n = i;
        while(n!= 0)
        {
            int rem = n%10;
            n = n/10;
            rev = rev*10 + rem;
        }
        if(rev == i)
        {
            palin.push_back(i);
        }
    }
    int n = palin.size();
    int i = 0, j = 1;
    int count = 1;
    //int n = palin.size();

    cout<<"all palindrome: "<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<palin[i]<<" ";
    }
    cout<<endl;
    //i = 0 j = 1;
    int ans = 1;
    while(i < j)
    {
        while(i != j && abs(palin[i] - palin[j]) <= C)
        {
            ans = max(ans, j - i + 1);
            j++;
           // j++;
        }
        cout<<"i: "<<i<<" num1: "<<palin[i]<<" j: "<<j<<" num2: "<<palin[j]<<endl;
        //ans = max(ans, j - i);
        while(abs(palin[i] - palin[j]) > C)
        {
            i++;
        }
    }    
    return ans;
}

int main(int argc, char ** argv)
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<" ans: "<<solve(a,b,c)<<endl;;
}

