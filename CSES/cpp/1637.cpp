#include <bits/stdc++.h>
using namespace std;

// int rec(int n,vector<int>&dp)
// {
    
//     if(n<=0)
//     return 0;
    
//     if(dp[n]!=-1)
//     return dp[n];
    
//     int ans=1e9;
//     int temp=n;
    
//     while(temp>0)
//     {
//         int d=temp%10;
//         if(d==0)
//       {
//           temp/=10;
//           continue;
//       }
//         ans=min(ans,1+rec(n-d,dp));
//         temp/=10;
//     }
    
//     return dp[n]=ans;
    
// }

int main() {
	// your code goes here
    int n;
    cin>>n;
    
    vector<int>dp(n+1,1e9);
    // int ans=rec(n,dp);
    
    dp[n]=0;
    for(int i=n;i>=1;i--)
    {
        int t=i;
           if (dp[i] == 1e9) continue;
            while(t>0)
            {
                int d=t%10;
                if(d==0)
                {
                    t/=10;
                    continue;
                }
                dp[i-d]=min(dp[i-d],1+dp[i]);
                t/=10;
            }
            
       
        
    }
    
    cout<<dp[0]<<endl;
    
    
}
