#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string a;
        cin>>a;
        
        int cnt1=0;
        int cnt0=0;
        
        for(int i=0;i<n;i++)
        {
            if(a[i]=='1')cnt1++;
            else cnt0++;
        }
        
        if(a[0]=='1')
        {
            cout<<cnt0<<endl;
            continue;
        }
        
        bool flag=false;
        int cur0=0;
        int cur1=0;
        
        int ans=1e9;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='1')
            {
                cur1++;
                
            }
            
            if(a[i]=='0')
            cur0++;
            
            int cost=cur1+(cnt0-cur0);
                ans=min(ans,cost);
            
        }
        
        cout<<ans<<endl;
       
    }
}