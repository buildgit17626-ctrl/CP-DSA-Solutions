#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        
        if((a+c)-b >= abs(a-b))
        {
            cout<<(a+c)-b<<endl;
        }
        else if((a+c)-b < abs(a-b))
        {
            cout<<abs(a-b)<<endl;
        }
    }
}