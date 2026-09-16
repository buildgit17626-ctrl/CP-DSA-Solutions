#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int MAXN = 200005;

long long inv[MAXN];

void precompute() {
    inv[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }


    sort(a.begin(), a.end());


    vector<long long> suff(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = (suff[i + 1] + a[i]) % MOD;
    }

 
    long long fact = 1;
    for (int i = 1; i <= n - 1; i++) {
        fact = (fact * i) % MOD;
    }

    long long total_cost = 0;

    for (int i = 0; i < n - 1; i++) {
        int vp= n - 1 - i;
    
        long long multiplier = (fact * inv[vp]) % MOD;
        long long parent_sum = (multiplier * suff[i + 1]) % MOD;
       
        long long nv = (fact * (a[i] % MOD)) % MOD;
        
    
        long long contribution = (parent_sum - nv + MOD) % MOD;
        
        total_cost = (total_cost + contribution) % MOD;
    }

    cout << total_cost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}