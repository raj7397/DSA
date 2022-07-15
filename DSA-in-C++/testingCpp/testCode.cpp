#include <iostream> 
#include <vector>

long partition(int n, int k);
using namespace std ;

   int main() {
       cout<<"long: "<<sizeof(long)<<endl;
       cout<<"double: "<<sizeof(double)<<endl;
       cout<<"long long: "<<sizeof(long long)<<endl;
      int n ;
      cin>>n ;
      int k ;
      cin>>k ;
      long ans = partition(n,k);
      cout<<ans<<endl;

     // write your code here
   }
   
 long partition(int n, int k)
 {
     vector<vector<long>>dp(k+1,vector<long>(n+1));
     for(int i = 0; i < dp.size(); i++)
     {
         for(int j = 0; j < dp[0].size(); j++)
         {
             if(i == 0 || j == 0)
             {
                 dp[i][j] = 0;
             }
             else if(i == 1)
             {
                 dp[i][j] = 1;
             }
             else if(i == j)
             {
                 dp[i][j] = 1;
             }
             else if(i > j)
             {
                 dp[i][j] = 0;
             }
             else{
                 dp[i][j] = dp[i][j - 1]*i + dp[i - 1][j - 1];
             }
         }
     }
     return dp[k][n];
 }