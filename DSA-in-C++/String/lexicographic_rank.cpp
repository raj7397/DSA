#include <iostream>
#include <string>
#include <vector>

using namespace std;

int rank_of_word(string str);
int fact(int n)
{
    int ans = 1;
    for(int i = 1; i <= n; i++)
    {
        ans = ans * i;
    }
    return ans;
}
int main(int agc, char **argv)
{
    string str;
    cin>>str;
    int ans = rank_of_word(str);
    cout<<"ans: "<<ans<<endl;
}
int rank_of_word(string str)
{
    vector<int>freq(256,0);
    for(int i = 0; i < str.length(); i++)
    {
        freq[str[i]]++;
    }
    for(int i = 1; i < 256; i++)
    {
        freq[i] = freq[i - 1] + freq[i];
    }
    int f = fact(str.length());
    int ans = 0;
    int n = str.length();
    for(int i = 0; i < str.length();i++)
    {
        f = f/(n - i);
        ans = ans + f * freq[str[i] - 1];
        for(int j = str[i]; j < 256; j++)
        {
            freq[j]--;
        }
    }
    return 1 + ans;

}