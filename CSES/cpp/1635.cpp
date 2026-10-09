#include <bits/stdc++.h>
using namespace std;

// Compiler optimization pragmas
#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int dp[1000001];
int mod = 1e9 + 7;

int rec(int level, int n, const vector<int>& a) {
    if (level == 0) return 1;
    if (dp[level] != -1) return dp[level];
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (level >= a[i]) {
            ans += rec(level - a[i], n, a);
            if (ans >= mod) ans -= mod; // Faster than % modulo
        }
    }
    
    return dp[level] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    if (!(cin >> n >> x)) return 0;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    memset(dp, -1, sizeof(dp));
    cout << rec(x, n, a) << "\n";
    
    return 0;
}