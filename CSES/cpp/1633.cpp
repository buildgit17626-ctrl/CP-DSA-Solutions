#include <bits/stdc++.h>
using namespace std;

long long dp[1000001];
int mod=1e9+7;
int rec(int level)
{
    
    //pruning 
    if(level<0)
    return 0;
    
    //basecase
    if(level==0)
    {
        return 1;
    }
    
    
    if(dp[level]!=-1)
    {
        return dp[level];
    }
    
    long long ans=0;
    
    for(int i=1;i<=6;i++)
    {
        if(level-i>=0)
        {
            ans+=rec(level-i);
            ans%=mod;
        }
        
    }
    
    return dp[level]=ans;
    
}


int main() {
	// your code goes here
    
    int n;
    cin>>n;
     memset(dp,-1,sizeof(dp));
    int ans=rec(n);
   
    cout<<ans%mod<<endl;
}
