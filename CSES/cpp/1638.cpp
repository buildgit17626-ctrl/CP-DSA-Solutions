#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    
    // Fix 1: Use == instead of =
    if(s[0][0] == '*') {
        dp[0][0] = 0;
    } else {
        dp[0][0] = 1;
    }
    
    int mod = 1e9 + 7;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[i][j] == '*') {
                continue;
            }
          
            if(j - 1 >= 0)
                dp[i][j] += dp[i][j - 1];
            if(i - 1 >= 0)
                dp[i][j] += dp[i - 1][j];
                
            // Fix 2: Apply modulo to the current state after all additions
            dp[i][j] %= mod;
        }
    }
    
    cout << dp[n-1][n-1] << endl;
    
    return 0;
}