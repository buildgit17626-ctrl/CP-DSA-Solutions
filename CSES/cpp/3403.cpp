#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    // dp[i][j] stores the length of LCS of a[0...i-1] and b[0...j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // 1. FORWARD PASS: Compute LCS length
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Output length first
    cout << dp[n][m] << "\n";

    if (dp[n][m] == 0) return 0;

    // 2. BACKWARD PASS: Reconstruct the sequence
    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs.push_back(a[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    // Print space-separated sequence on the second line
    for (int k = 0; k < (int)lcs.size(); k++) {
        cout << lcs[k] << (k + 1 == (int)lcs.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}