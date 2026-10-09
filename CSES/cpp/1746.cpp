#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    
    int n,m;
    cin>>n>>m;
    
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    
    int mod=1e9+7;
    vector<vector<int>>dp(n,vector<int>(m+2));
    
    if(a[0]==0)
    {
        for(int i=1;i<=m;i++)
        {
            dp[0][i]=1;
        }
    }
    else
    {
        dp[0][a[0]]=1;
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]!=0 && a[i]!=j)
             dp[i][j]=0;
            else
            {
                long long ways = dp[i-1][j-1];
                ways = (ways + dp[i-1][j]) % mod;
                ways = (ways + dp[i-1][j+1]) % mod;
                
                dp[i][j]=ways;
            }
        }
        
    }
    
    long long cnt=0;
    for(int i=1;i<=m;i++)
    {
        cnt=(cnt+dp[n-1][i])%mod;
    }
    cout<<cnt<<endl;
}
