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
        vector<int>a(2*n+1);
        for(int i=1;i<=2*n;i++)cin>>a[i];
        
        vector<long long> dp(2 * n + 1, 0);
    vector<int> first_pos(n + 1, -1);
    
    for (int i = 1; i <= 2 * n; i++) {
       
        dp[i] = dp[i - 1] + 1;
        
       
        if (first_pos[a[i]] != -1) {
            int p = first_pos[a[i]];
            long long len = i - p + 1;
            dp[i] = max(dp[i], dp[p - 1] + len * len);
        } else {
            first_pos[a[i]] = i;
        }
    }
        
        cout<<dp[2*n]<<endl;
    }
}