#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    
    int a,b;
    cin>>a>>b;
    
    
    int m=b;
    int n=a;
    vector<vector<long long>>dp(a+1,vector<long long>(m+1,0));
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==j)
            {
                dp[i][j]=0;
                continue;
            }
            
            long long mini=1e9;
            
            for(int k=1;k<=i/2;k++)
            {
                mini=min(mini, 1+dp[k][j]+dp[i-k][j]);
            }
            
            for(int k=1;k<=j/2;k++)
            {
                mini=min(mini,1+dp[i][k]+dp[i][j-k]);
            }
            
            dp[i][j]=mini;
        }
    }
    
    cout<<dp[a][b]<<endl;
}
