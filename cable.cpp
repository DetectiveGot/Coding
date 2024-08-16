#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
ll a[N], dp[N], tar;
vector<int> g[N];
// if already visit no need to add weight
// graph LIS?
// if < x not pick

inline void dfs(int u, int p){
	dp[u]=u==tar?0:1e9;
	for(auto &e:g[u]){
		if(e==p) continue;
		pa[e]=u;
		dfs(e, u);
	}
}

inline void dfs2(int u, int p)

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,s,t,u,v; cin >> n >> s >> t;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<n;i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int q,x; cin >> q;
	while(q--){
		cin >> x;
		tar = x;
		vector<int> lis;
		dfs(s, -1);
		u = x;
		int pv = -1;
		while(u!=s){
			auto it = lower_bound(lis.begin(), lis.end(), a[u]);
			if(it==lis.end()) lis.push_back(a[u]);
			else *it = a[u];
			u = pa[u];
		}
		dfs2()
		if(n==3){
			if(a[s]>a[x] && a[x]>a[t]) cout << "3\n";
			else cout << "1\n";
		}
	}

	return 0;
}
