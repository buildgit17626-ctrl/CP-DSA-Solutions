#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    
    int q,k;
    cin>>q>>k;
    
    int mod=998244353;
    vector<int>a;
    vector<long long>dp(k+1);
        dp[0]=1;
    while(q--)
    {
    char ch;
    int p;
    cin>>ch>>p;
    
    // if(ch=='+')
    // {
    //     a.push_back(p);
    // }
    // else
    // {
    //     auto it=find(a.begin(),a.end(),p);
    //     if(it != a.end())a.erase(it);
    // }
    
  

    
    // for(int j=1;j<=k;j++)
    // {
    // for(int i=0;i<a.size();i++)
    // {
    //      for(int j=k;j>=0;j--)
    // {
    //   if(j-a[i]>=0)
    //   {
    //       dp[j]+=dp[j-a[i]];
    //       dp[j]%=mod;
    //   }
    // }
    // }
    
    if(ch=='-')
    {
    for(int j=p;j<=k;j++)
    {
      dp[j]=(dp[j]-dp[j-p]+mod)%mod;
    }
    }
    else
    {
         for(int j=k;j>=0;j--)
    {
      if(j-p>=0)
      {
          dp[j]+=dp[j-p];
          dp[j]%=mod;
      }
    }
    }
     
     if(dp[k]>0)
     {
         cout<<dp[k]<<endl;
     }
     else
     cout<<0<<"\n";
     
     
    }
    
}