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
        vector<int>a(n);
        int mini=INT_MAX;
        for(int i=0;i<3;i++)
        {
            cin>>a[i];
            mini=min(mini,a[i]);
        }
        
        
         
         
       
       cout<<n-mini<<endl;
        
    }
    
}