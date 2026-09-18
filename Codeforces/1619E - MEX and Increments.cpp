#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    
    vector<long long> ans(n + 1, -1);
    multiset<long long> extras; 
    long long total_cost = 0;
    bool impossible = false;
    
    for (int i = 0; i <= n; i++) {
        if (impossible) {
            ans[i] = -1;
            continue;
        }
        
     
        ans[i] = total_cost + freq[i];
        
 
        if (freq[i] == 0) {
           
            auto it = extras.lower_bound(i);
            
            if (it == extras.begin()) {
               
                impossible = true;
            } else {
                it--; 
                total_cost += (i - *it);
                extras.erase(it);
            }
        } else {
          
            for (int k = 1; k < freq[i]; k++) {
                extras.insert(i);
            }
        }
    }
    
    for (int i = 0; i <= n; i++) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}