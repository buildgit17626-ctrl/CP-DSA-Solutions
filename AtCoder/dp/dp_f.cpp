#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define cin(v)                              \
    for (int i = 0; i < (int)v.size(); i++) \
    cin >> v[i]
#define fx(s) fixed << setprecision(s)
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define MUN cout << "-1\n"
using namespace std;

//----------->Definitions<------------------------------

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
const ll OO = 2'000'000'000'000'000'000LL;
constexpr int MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
constexpr int SZ = 100006;
constexpr double EPS = 1e-15;

//  Eight directions
// int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
// int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

//  Four directions
// int dx[] = { -1,0, 0, 1, };
// int dy[] = { 0, -1,1,0, };

// how Kight moves in chess
// int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
// int dy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

//(Ordered_multiset)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_multiset = tree<
    T,
    null_type,
    less_equal<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

string s, t;
int n, m;
int memo[3001][3001];

int go(int i, int j) {
    if (i >= n || j >= m) {
        return 0;
    }
    int& ret = memo[i][j];
    if (~ret)return ret;


    if (s[i] == t[j]) {
        return ret = go(i + 1, j + 1) + 1;
    }
    int ch1 = go(i + 1, j);
    int ch2 = go(i, j + 1);

    return ret = max(ch1, ch2);


}
string res;
void build(int i, int j) {
    
    if (i >= n || j >= m) {
        return;
    }

    if (s[i] == t[j]) {
        res += s[i];
        return build(i + 1, j + 1);
    }
    int ch1 = go(i + 1, j);
    int ch2 = go(i, j + 1);
    if (ch1 > ch2) {
        build(i + 1, j);
    }
    else {
        build(i, j + 1);
    }

    return;
}

void  solve()
{
    memset(memo, -1, sizeof(memo));
    cin >> s >> t;
    n = s.size();
    m = t.size();

    build(0,0);
    cout<<res;


    return;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //  freopen("pal.in", "r", stdin);
    /*freopen("output.txt", "w", stdout);*/

    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++)
    {
        solve();
    }
    return 0;
}