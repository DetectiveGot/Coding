#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long

using namespace std;

const int N = 1e5+2;
struct DATA{
	int u,v,w;
};
vector<DATA> g;
vector<int> adj[N], adj2[N];
ll dp[N];
bool vis[N], vis2[N], cycle[N];

void dfs(int u){
	vis[u]=1;
	for(auto&e:adj[u]){
		if(!vis[e]) dfs(e);
	}
}

void dfs2(int u){
	vis2[u]=1;
	for(auto&e:adj2[u]){
		if(!vis2[e]) dfs2(e);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	int u,v,w;
	for(int i=0;i<m;i++){
		cin >> u >> v >> w;
		g.push_back({u,v,w});
		adj[u].push_back(v);
		adj2[v].push_back(u);
	}
	for(int i=1;i<=n;i++) dp[i]=-1e18;
	dp[1]=0;
	dfs(1), dfs2(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			u=g[j].u, v=g[j].v, w=g[j].w;
			if(dp[u]==-1e18) continue;
			if(dp[u]+w>dp[v]){
				if(i==n-1) cycle[v]=1;
				dp[v]=max(dp[v], dp[u]+w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i] && vis2[i] && cycle[i]){
			cout << -1;
			return 0;
		}
	}
	cout << dp[n];
	
	return 0;
}
