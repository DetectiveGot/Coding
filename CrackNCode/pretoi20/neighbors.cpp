#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1, inf = INT_MIN>>1;
ll dp[N], ans[N], a[N];
vector<pii> g[N];

inline void dfs(int u, int p){
	dp[u]=inf;
	for(auto &e:g[u]){
		if(e.first==p) continue;
		dfs(e.first, u);
		dp[u]=max(dp[u], dp[e.first]+e.second);
	}
	if(a[u]) dp[u]=0;
}

inline void dfs2(int u, int p, ll val){
	if(a[u]) val=0;
	ans[u]=max(dp[u], val);
	vector<pii> v{{val, -1}};
	for(auto &e:g[u]){
		if(e.first==p) continue;
		v.push_back({dp[e.first]+e.second, e.first});
	}
	v.push_back({inf,-1});
	sort(v.begin(), v.end(), greater<pii>());
	for(auto &e:g[u]){
		if(e.first==p) continue;
		dfs2(e.first, u, (a[u]?e.second:e.first==v[0].second?v[1].first+e.second:v[0].first+e.second));
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,q,u,v,w; cin >> n >> q;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n-1;i++){
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dfs(0, -1);
	dfs2(0, -1, inf);
	int t;
	while(q--){
		cin >> t;
		cout << ans[t] << "\n";
	}

	return 0;
}
