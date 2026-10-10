#include <iostream>
#include <vector>
#include <algorithm>

//AI Solution Check

using namespace std;

// Maximum possible sum of powers of 5: 
// n <= 200, and max powers of 5 in 10^18 is log5(10^18) ≈ 27. 
// 200 * 27 = 5400. We use 5405 for safety.
const int MAX_5 = 5405;

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        
        // Count factors of 2
        int c2 = 0;
        long long temp = a;
        while (temp > 0 && temp % 2 == 0) {
            c2++;
            temp /= 2;
        }
        
        // Count factors of 5
        int c5 = 0;
        temp = a;
        while (temp > 0 && temp % 5 == 0) {
            c5++;
            temp /= 5;
        }
        
        items[i] = {c2, c5};
    }

    // dp[c][j] = max powers of 2 achievable using exactly 'c' numbers 
    // with a total power of 5 sum equal to 'j'
    vector<vector<int>> dp(k + 1, vector<int>(MAX_5, -1));
    dp[0][0] = 0; // Base case: 0 numbers chosen, 0 sum of 5s, 0 sum of 2s

    for (int i = 0; i < n; i++) {
        int cnt2 = items[i].first;
        int cnt5 = items[i].second;

        // 0/1 Knapsack loop running backwards to prevent reusing the same number
        for (int c = min(k, i + 1); c >= 1; c--) {
            for (int j = MAX_5 - 1; j >= cnt5; j--) {
                if (dp[c - 1][j - cnt5] != -1) {
                    dp[c][j] = max(dp[c][j], dp[c - 1][j - cnt5] + cnt2);
                }
            }
        }
    }

    // Find the maximum roundness min(total_2, total_5) for valid subsets of size k
    int max_roundness = 0;
    for (int j = 0; j < MAX_5; j++) {
        if (dp[k][j] != -1) {
            max_roundness = max(max_roundness, min(j, dp[k][j]));
        }
    }

    cout << max_roundness << "\n";

    return 0;
}