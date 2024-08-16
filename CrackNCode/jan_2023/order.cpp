#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5+2, mod = 1e9+7;
ll cnt[N], dp[N], fac[N], inv[N];
vector<int> g[N];

void dfs(int u, int p){
	cnt[u]=1;
	for(auto&e:g[u]){
		if(e==p) continue;
		dfs(e, u);
		cnt[u]+=cnt[e];
	}
}

ll ncr(ll n, ll r){
	return ((fac[n]*inv[n-r])%mod*inv[r])%mod;
}

void dfs2(int u, int p){
	dp[u]=1;
	int n=cnt[u]-1;
	for(auto&e:g[u]){
		if(e==p) continue;
		dfs2(e, u);
		dp[u]=((dp[u]*ncr(n, cnt[e]))%mod*dp[e])%mod;
		n-=cnt[e];
	}
}

ll bp(ll a, ll b){
	ll res=1;
	while(b){
		if(b&1) res=(res*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,u,v; cin >> n;
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=(fac[i-1]*i)%mod;
		inv[i]=bp(fac[i], mod-2);
	}
	for(int i=1;i<n;i++){
		cin >> u >> v;
		g[v].push_back(u);
	}
	dfs(1, -1);
	dfs2(1, -1);
	cout << dp[1];
	
	return 0;
}