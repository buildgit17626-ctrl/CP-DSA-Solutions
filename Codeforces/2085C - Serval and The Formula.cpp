#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        
        int ans=0;
        if(x==y)
        {
            cout<<-1<<endl;
            continue;
        }
        
        // for(int i=0;i<31;i++)
        // {
        //     int p=((1<<i) & x);
        //     int p1=((1<<i)& y);
        //     if((((1<<i) & x)>0) && (((1<<i)& y)>0))
        //     {
            
        //         while(i<32 && (((1<<i)&x)!=0 || ((1<<i)&y)!=0))
        //         {
        //             i++;
        //         }
        //         int p2=((1<<i)&x);
        //         int p3=((1<<i)&y);
        //         ans|=(1<<i);
        //     }
        // }
        
        // int maxi=max(x,y);
        // bool flag=false;
        // for(int i=31;i>=0;i--)
        // {
        //     if(((1<<i)&ans)>=1)
        //     {
        //         flag=true;
        //     }
            
        //     if(!flag && ((((1<<i)&maxi)>0) && (((1<<i)&ans)==0)))
        //     ans|=(1<<i);
        // }
        
        
        if(x&y==0)
        cout<<0<<endl;
        else
        cout<<abs(1LL*((1LL<<34)-max(x,y)))<<endl;
    }
}