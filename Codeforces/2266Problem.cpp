/*
     There's always a way
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// // For making pbds multiset with erase functionality working as expected,
// // change less<int> to less_equal<int> and use find_by_order to remove exact value.
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;



const bool multipleTestCases = 1;

const ll maxn = 2000005;
vll spf(maxn,0);
vll dp(maxn,0);

void precompute(){
    f(i,2,maxn) spf[i] = i;
    for(ll i=2;i*i<maxn;i++){
        if(spf[i] == i){
            for(ll j=i*i;j<maxn;j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    } 
}


void solve(){
    /*
      
        cost(x) = 1+ p*Cost(x/p)

        choose 
            x > k
            p <= x

        if x prime -> only single operation
        else total primes cost;
        cuz x/p -> removes that prime but other primes and pwoers are still elft;
        

    */
    ll n,k;cin>>n>>k;
    vll arr(n);
    f(i,0,n){
        cin>>arr[i];
    }


    vll dp(n+1,0);
    
    // since all a[i] <= n, computer dp for all n
    f(v,1,n+1){
        if(v <= k){
            dp[v] = 0;
            continue;
        }

        ll bestops = 1e18;
        ll temp = v;

        while(temp > 1){
            ll p = spf[temp];
            ll currops = 1 + p*dp[v / p];
            bestops = min(bestops, currops);

            while(temp % p == 0) temp/=p;
        }

        dp[v] = bestops;

    }


    
    ll ans=0;
    f(i,0,n){
        ans += dp[arr[i]];
    }

    cout << ans<<"\n";


}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    precompute();
    ll t = 1;if(multipleTestCases) cin >> t;
    while(t--){solve();}
    return 0;
}