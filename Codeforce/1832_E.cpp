#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e7+2, mod = 998244353;
ll a[N];

ll mul(ll x, ll y, ll m){
	return (x*y)%m;
}

ll add(ll x, ll y, ll m){
	return (x+y+m)%m;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,x,y,m,k; cin >> n >> a[1] >> x >> y >> m >> k;
	ll ans=0;
	for(int i=2;i<=n;i++) a[i]=add(mul(a[i-1], x, m), y, mod);
	for(int i=0;i<=k;i++){
		for(int i=1;i<=n;i++){
			a[i]=add(a[i], a[i-1], m);
		}
	}
	for(int i=1;i<=n;i++) ans^=(a[i-1]*i);
	cout << ans;
	
	return 0;
}
