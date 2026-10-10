#include <bits/stdc++.h>
using namespace std;


bool possible(int budg, vector<int>&freq,int k,int n) {
        vector<int> cnt = freq;

       
        int current = k + n + 2 * budg - 1;
        int splits = 0;

        for (int x = n; x >= 1; x--) {
            
            int removable = max(0, current - x + 1);
            int erased= min(cnt[x], removable);
            current -= erased;

            int rem = cnt[x] - erased;
            splits += rem;

            if (splits > budg)
                return false;

            if (rem > 0) {
                if (x == 1)
                    return false;

                cnt[(x + 1) / 2] += 2 * rem;
            }
        }

        return true;
    }

int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
    
    int n, k;
    cin >> n >> k;

    vector<int> freq(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        freq[x]++;
    }

    

    int low = 0, high = n;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (possible(mid,freq,k,n))
            high = mid;
        else
            low = mid + 1;
    }

    cout << n + 2 * low <<endl;
    }
}

