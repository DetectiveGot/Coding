#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2005, mxN = 4e6+1;
ll a[N], qs[N];
bitset<mxN> dp;
vector<int> v;

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,k;
	cin >> n >> k;
	ll mx=0, ans=0;
	for(int i=1; i<=n; i++) cin >> a[i], v.push_back(a[i]);
	for(int i=1;i<=n;i++) qs[i]=qs[i-1]+a[i];
	if(k) {
		dp.set(0);
		for(int i=1;i<=n;i++) dp|=dp<<a[i];
		for(int i=1;i<=qs[n]/2;i++) if(dp[i]) mx=max(mx, (qs[n]-i)*i);
	}
	for(int i=1; i<=n; i++) ans+=a[i]*(qs[n]-qs[i]);
	if(k) ans-=mx;
	cout << ans;

	return 0;
}