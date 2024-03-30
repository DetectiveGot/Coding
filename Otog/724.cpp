#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
vector<int> adj[N], adj2[N];
bool vis[N], vis2[N], ban[N], can[N], can2[N];
vector<pii> ask;

inline void dfs(int u){
	vis[u]=1;
	can[u]=1;
	for(auto &e:adj[u]){
		if(vis[e]) continue;
		if(ban[e]){
			can[e]=1;
			continue;
		}
		dfs(e);
	}
}

inline void dfs2(int u){
	vis2[u]=1;
	can2[u]=1;
	for(auto &e:adj2[u]){
		if(vis2[e]) continue;
		if(ban[e]){
			can2[e]=1;
			continue;
		}
		dfs2(e);
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,qu,u,v; cin >> n >> m >> qu;
	for(int i=0;i<m;i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj2[v].push_back(u);
	}
	for(int i=0;i<qu;i++){
		cin >> u >> v;
		if(u==1) ban[v]=1;
		ask.push_back({u,v});
	}
	reverse(ask.begin(), ask.end());
	stack<bool> ans;
	if(!ban[1]) dfs(1);
	if(!ban[n]) dfs2(n);
	for(auto &e:ask){
		if(e.first==1){
			ban[e.second]=0;
			if(can[e.second]) dfs(e.second);
			if(can2[e.second]) dfs2(e.second);
		} else ans.push(vis[e.second]&vis2[e.second]);
	}
	while(!ans.empty()){
		cout << ans.top() << "\n";
		ans.pop();
	}

	return 0;
}

