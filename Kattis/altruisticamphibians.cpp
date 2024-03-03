#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1, W = 1e8+1;
struct DATA{
	ll l,w,h;
	bool operator < (const DATA &dt) const{
		return w>dt.w;
	}
} a[N];
ll dp[W];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	ll n,d; cin >> n >> d;
	for(int i=1;i<=n;i++) cin >> a[i].l >> a[i].w >> a[i].h;
	int ans=0;
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i].l+dp[a[i].w]>d) ++ans;
		for(int j=1;j<a[i].w;j++){
			if(j+a[i].w<W) dp[j]=max(dp[j], dp[j+a[i].w]+a[i].h);
			dp[j]=min(dp[j], d);
		}
	}
	cout << ans;

	return 0;
}

