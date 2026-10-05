#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    
    for(int i=0;i<n;i++)cin>>a[i];
    
    vector<vector<long long>>dp(k+1,vector<long long>(k+1,0));
    
    dp[0][0]=1;
    
    for(int i=0;i<n;i++)
    {
        for(int j=k;j>=0;j--)
        {
            for(int l=j;l>=0;l--)
            {
                if(dp[j][l]) // you could have also written in subtraction 
                {
                    if(j+a[i]<=k)
                    {
                        dp[j+a[i]][l]=1; //trans of not putting in current subset
                        if(l+a[i]<=k)
                        {
                            dp[j+a[i]][l+a[i]]=1; //transi of putting in the current subset
                        }
                    }
                }
            }
        }
    }
    
    vector<long long>ans;
    for(int i=0;i<=k;i++)
    {
        if(dp[k][i])
        {
            ans.push_back(i);
        }
    }
    
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}