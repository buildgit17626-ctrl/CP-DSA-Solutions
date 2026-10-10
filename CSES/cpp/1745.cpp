#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    
    for(int i = 0; i < n; i++) {
       
        for(int j = sum; j >= a[i]; j--) {
            if(dp[j - a[i]]) {
                dp[j] = true; 
            }
        }
    }
    
    int cnt = 0;
    for(int i = 1; i <= sum; i++) {
        if(dp[i]) {
            cnt++;
        }
    }
    
    cout << cnt << '\n';
    for(int i = 1; i <= sum; i++) {
        if(dp[i]) {
            cout << i << " ";
        }
    }
    
    return 0;
}