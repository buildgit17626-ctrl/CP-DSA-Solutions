#include <bits/stdc++.h>
using namespace std;

// int rec(int lvl, vector<int>&s, vector<int>&p,  int x)
// {
//     if(lvl>=n ||  x<0)return 0;
    
//     if(dp[lvl][x]!=-1)return dp[lvl][x];
    
//     int ans=-1e9;
    
//     ans=rec(lvl+1,s,p,x);
//     ans=max(ans, s[lvl]+rec(lvl+1,s,p,x-p[lvl]));
    
//     return dp[lvl][x]=ans;
// }

int main() {
	// your code goes here
    
    int n,x;
    cin>>n>>x;
    vector<int>s(n); //pages
    vector<int>p(n); //price 
    
    for(int i=0;i<n;i++)cin>>p[i];
    for(int i=0;i<n;i++)cin>>s[i];
    
    vector<int>dp(x+1);
    
    // for(int i=0;i<=x;i++)
    // {
    //     int tot=0;
    //     for(int j=0;j<n;j++)
    //     {
    //       dp[i&1][j]=max(dp[1&i][j], s[j]+dp[1&i][j]);
    //     }
    // }
    
    for(int i=0;i<n;i++)
    {
        for(int j=x;j>=p[i];j--)
        {
            dp[j]=max(dp[j], s[i]+dp[j-p[i]]);
        }
    }
    
    
    cout<<dp[x]<<endl;
    
}
