#include <bits/stdc++.h>
using namespace std;
#define int long long
const int OO = 2e18, LOG = 20, MOD = 1e9 + 7, N = 2e5 + 5;

int n,a[21][21],dp[21][1<<21];
int calc(int i,int msk)
{
    if(i == n)return 1;
    int&ret=dp[i][msk];
    if(~ret)return ret;
    ret =0;
    for(int j = 0;j<n;j++)
    {
        if((msk >> j )& 1)continue;
        if(a[i][j]){
            ret = (ret + calc(i+1 , msk | (1ll << j)))%MOD;
        }
    }
    return ret;
}
void nageh()
{
    cin >> n ;
    for(int i = 0 ;i<n;i++)for(int j = 0 ;j<n;j++)cin >> a[i][j];
    memset(dp,-1,sizeof dp);
    cout << calc(0 , 0)<<'\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        nageh();
}