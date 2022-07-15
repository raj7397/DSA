#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solve(vector<int> &A, int B) 
{
    int m = A.size();
    int n = B;
    bool dp[m + 1][n + 1];

    for(int i = 0; i < m + 1; i++)
    {
        for(int j = 0; j < n + 1; j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if(j == 0)
            {
                dp[i][j] = true;
            }
            else if(i == 0)
            {
                dp[i][j] = false;
            }
            else {
                bool incl =false;
                if(A[i - 1] <= j)
                {
                    incl = dp[i - 1][j - A[i -1]];

                }
                dp[i][j] = dp[i - 1][j] || incl;
            }
        }
        
    }
    return dp[m][n];

}
int main(int argc , char **argv)
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(5);
    int sum = 7;
    cout<<"an; "<<solve(arr,sum);
}