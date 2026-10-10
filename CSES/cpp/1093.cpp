#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    long long sum = n * (n + 1) / 2;

    
    if (sum % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    int target = sum / 2;
    int mod = 1e9 + 7;

    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    // Loop up to n - 1 to fix element n in the other set
    for (int i = 1; i < n; i++) {
        for (int j = target; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }

    cout << dp[target] << "\n";

    return 0;
}