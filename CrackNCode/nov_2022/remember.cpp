#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int mxN = 2e5+1;
vector<int> adj[mxN], g[mxN];
ll val[mxN], lz[mxN];

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,u,v;
	cin >> n >> m;
	int sq=sqrt(n);
	for(int i=0; i<m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1; i<=n; i++) {
		if(adj[i].size()>=sq) {
			for(auto &e:adj[i]) 
				if(adj[e].size()>=sq)  g[i].push_back(e);
		} else for(auto &e:adj[i]) g[i].push_back(e);
	}
	int q; cin >> q;
	ll x,y;
	char cmd;
	while(q--) {
		cin >> cmd;
		if(cmd=='U') {
			cin >> x >> y;
			if(adj[x].size()>=sq)  lz[x]+=y;
			else {
				val[x]+=y;
				for(auto &e:adj[x]) val[e]+=y;
			}
		} else {
			cin >> x;
			ll ans=val[x]+lz[x];
			for(auto &e:g[x]) ans+=lz[e];
			cout << ans << "\n";
		}
	}

	return 0;
}