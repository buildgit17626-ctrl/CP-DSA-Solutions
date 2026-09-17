#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    
    int t;
    cin>>t;
    while(t--)
    {
        string n;
        cin>>n;
        
        string ans="";
        int idx=-1;
        int idx2=-1;
        for(int i=0;i<n.length();i++)
        {
            if(n[i]=='0')
            {
                idx=i;
                break;
            }
        }
        
        for(int i=0;i<n.length();i++)
        {
            if(n[i]=='1')
            {
                idx2=i;
                break;
            }
        }
        
        for(int i=0;i<n.length();i++)
        {
            if(i==idx || i==idx2)
            continue;
            
            ans+=n[i];
        }
        
        cout<<ans<<endl;
    }
}