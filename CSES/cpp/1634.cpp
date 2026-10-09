#include <bits/stdc++.h>
using namespace std;

long long dp[1000001];
int mod=1e9+7;
long long rec(int level, int n, vector<int>&a)
{
    
    //pruning 
    if(level<0)
    return -1;
    
    //basecase
    if(level==0)
    {
        return 1;
    }
    
    
    if(dp[level]!=-1)
    {
        return dp[level];
    }
    
    long long ans=1e7;
    
    for(int i=0;i<n;i++)
    {
        if(level-a[i]>=0)
        {
            ans=min(ans,rec(level-a[i],n,a)+1);
        }
    }
    
    return dp[level]=ans;
    
}


int main() {
	// your code goes here
    
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    
     memset(dp,-1,sizeof(dp));
    int ans=rec(x,n,a);
    if(ans!=1e7)
    cout<<ans%mod-1<<endl;
    else
    cout<<-1<<endl;
}
