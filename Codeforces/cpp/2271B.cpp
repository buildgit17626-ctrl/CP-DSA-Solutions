#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
            mpp[a[i]]++;

        bool flag = false;
        vector<int> s1;
        vector<int> s2;

        for (int i = 0; i <= n; i++) {
            if (mpp[i] == 0)
                break;

            
            int cnt = (mpp[i] + 1) / 2;
            s1.push_back(cnt);
            s2.push_back(mpp[i] - cnt);
        }

        for (int i = 0; i < (int)s1.size(); i++) {
          
            if (s1[i] < k && s2[i] < k)
                break;

            if ((s1[i] >= k && s2[i] < k) ||
                (s1[i] < k && s2[i] >= k)) {
                flag = true;
                break;
            }
        }

        if(flag)
        {
            cout<<"YES"<<endl;
        }
        else
        cout<<"NO"<<endl;
    }
}