#include <bits/stdc++.h>
using namespace std;

//   int dp[2][1000001];
// int rec(vector<int>&a, int lvl,int p)
// {
//     if(lvl>=a.size())
//     return 0;
    
//     if(dp[p][lvl]!=-1)
//     {
//         return dp[p][lvl];
//     }
    
    
//     long long ans=1e9;
    
//     if(p==0)
//     {
//         ans=min(ans,1LL*rec(a,lvl+1,1)+(a[lvl])); 
//         if(lvl+1<a.size())
//         ans=min(ans,1LL*rec(a,lvl+2,1)+a[lvl]+a[lvl+1]);
//     }
//     else
//     {
//         ans=min(ans,1LL*rec(a,lvl+1,0));
//         if(lvl+1<a.size())
//         ans=min(ans,1LL*rec(a,lvl+2,0));
//     }
    
//     return dp[p][lvl]=ans;
   
    
// }

int main() {
	// your code goes here
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        
//      for (int i = 0; i <= n; i++) {
//     dp[0][i] = -1;
//     dp[1][i] = -1;
// }
       // Initialize everything to 0 to handle base cases safely
vector<vector<long long>> dp(2, vector<long long>(n + 2, 0));
       
        for(int i=n-1;i>=0;i--)
        {
            //1st situation
             dp[0][i]=dp[1][i+1]+a[i];
             if(i+1<n)
             {
                dp[0][i]=min(dp[0][i], dp[1][i+2]+a[i+1]+a[i]);
             }
             
             dp[1][i]=dp[0][i+1];
             if(i+1<n)
             {
                dp[1][i]=min(dp[1][i], dp[0][i+2]);
             }
            
        }
        
        long long ans=dp[0][0];
        
        cout<<ans<<endl;
    }
}