#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    
    int t;
    cin>>t;
    int n = 1e6;

vector<vector<long long>>dp(2, vector<long long>(n+1));
 int mod=1e9+7;
  dp[0][1]=1;
        dp[1][1]=1;

for(int i=2;i<=n;i++)
        {
          dp[0][i]=(2*dp[0][i-1]+dp[1][i-1])%mod;
          dp[1][i]=(dp[0][i-1]+4*dp[1][i-1])%mod;
        }
    while(t--)
    {
        int x;
        cin>>x;
        
        
        
      
        
        
        long long cnt=(dp[0][x]+dp[1][x])%mod;
        
        
        
        cout<<cnt<<endl;
    }
}
