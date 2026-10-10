#include <bits/stdc++.h>
using namespace std;

int main() {
   
    
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        
        
        if (b <= a && (a % 2 == b % 2)) {
            cout << a << endl;
        }
       
        else if (b <= a + 1 && ((a + 1) % 2 == b % 2)) {
            cout << a + 1 << endl;
        }
       
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}
