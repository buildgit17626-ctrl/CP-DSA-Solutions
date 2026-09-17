#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    
    
    if(n < (m * 2)) {
        cout << "NO\n";
        return;
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    bool possible = true;
    for(int i = 0; i < m; i++) {
        
        if(a[i] > b[i] || a[n - m + i] < b[i]) {
            possible = false;
            break;
        }
    }
    
    if(possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O is recommended for Codeforces
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}