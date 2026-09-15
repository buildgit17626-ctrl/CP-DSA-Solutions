#include <bits/stdc++.h>
// Include the PBDS libraries
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Define the ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    // Fast I/O is crucial for large inputs on Codeforces
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if(cin >> t) {
        while(t--) {
            int n;
            cin >> n;
            vector<vector<int>> a(n, vector<int>(2));
            for(int i = 0; i < n; i++) {
                cin >> a[i][0];
                cin >> a[i][1];
            }
            
            // Sort by starting positions
            sort(a.begin(), a.end());
            
            ordered_set s; // Use PBDS instead of std::set
            long long cnt = 0;
            
            for(int i = 0; i < n; i++) {
                // order_of_key gives the count of elements strictly smaller than a[i][1]
                int strictly_less = s.order_of_key(a[i][1]);
                
                // The number of elements GREATER than a[i][1] is total size - strictly_less
                int curr = s.size() - strictly_less;
                
                cnt += curr;
                
                // Insert the current end point into the ordered_set
                s.insert(a[i][1]);
            }
            
            cout << cnt << endl;
        }
    }
    return 0;
}