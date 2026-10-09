#include <bits/stdc++.h>
using namespace std;



// long long rec(vector<int>&a,int lvl,int s,vector<vector<int>>& dp)
// {
//     if(s==0)
//     return 1;
//     if(lvl>=a.size() || s<0)
//     return 0;
    
//     if(dp[lvl][s]!=-1)
//     return dp[lvl][s];
    
//     long long ans=0;
    
//     ans=(ans+rec(a,lvl+1,s,dp))%mod;
//     ans=(ans+rec(a,lvl,s-a[lvl],dp))%mod;
   
    
//     return dp[lvl][s]=ans;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int mod = 1e9 + 7;
    
    // dp[i] will store the number of ways to make sum i
    vector<int> dp(x + 1, 0);
    dp[0] = 1; // Base case: 1 way to make sum 0 (use no coins)
    
    // Loop through each coin
    for(int i = 0; i < n; i++) {
        // Update dp array for all weights from a[i] to x
        for(int s = a[i]; s <= x; s++) {
            dp[s] = (dp[s] + dp[s - a[i]]) % mod;
        }
    }
    
    cout << dp[x] << "\n";
    
    return 0;
}