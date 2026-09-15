#include<bits/stdc++.h>
using namespace std;
typedef long long gh;
gh n;
struct df
{
	gh h,x,i;
};
df a[200005];
gh dp[200005];
gh t[2000005];
bool cmp(df a,df b)
{
	return a.h<b.h;
}
void updt(gh v,gh d,gh c,gh ps,gh val)
{
	if(d>c)return;
	if(d==c)
	{
		t[v]=max(t[v],val);
		return;
	}
	gh giua=(d+c)/2;
	if(ps<=giua)
		updt(2*v,d,giua,ps,val);
	else
		updt(2*v+1,giua+1,c,ps,val);
	t[v]=max(t[2*v],t[2*v+1]);
}
gh get(gh v,gh d,gh c,gh l,gh r)
{
	if(l>c||r<d)return 0;
	if(l<=d&&r>=c)return t[v];
	gh giua=(d+c)/2;
	return max(get(2*v,d,giua,l,r),get(2*v+1,giua+1,c,l,r));
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("bai1.inp","r",stdin);
	// freopen("bai1.out","w",stdout);
	cin>>n;
	for(gh i=1;i<=n;i++)
	{
		cin>>a[i].h;
	}
	for(gh i=1;i<=n;i++)
	{
		cin>>a[i].x;
		a[i].i=i;
	}
	sort(a+1,a+n+1,cmp);
	// for(gh i=1;i<=n;i++)
	// {
	// 	cout<<a[i].h<<" "<<a[i].x<<"\n";
	// }
	for(gh i=1;i<=n;i++)
	{
		gh vt=a[i].i;
		gh best=get(1,1,n,1,vt);
		// cout<<a[i].x<<" "<<vt<<" "<<best<<"\n";
		dp[i]=best+a[i].x;
		updt(1,1,n,vt,dp[i]);
	}
	gh sln=-1e9;
	for(gh i=1;i<=n;i++)
	{
		sln=max(sln,dp[i]);
		// cout<<a[i].h<<" "<<dp[i]<<"\n";
	}
	cout<<sln;
}