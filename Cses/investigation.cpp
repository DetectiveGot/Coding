#include<bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>

using namespace std;
struct DATA{
	int ux;
	ll dx;
	bool operator < (const DATA &dt) const{
		return dx>dt.dx;
	}
};
const int N = 1e5+2, mod=1e9+7;
bool vis[N];
ll dist[N];
int dp[N], dp2[N], dp3[N],n;
vector<pii> g[N];
vector<int> adj[N];
priority_queue<DATA> pq;

void dfs(int u){
	vis[u]=1;
	for(auto&e:adj[u]){
		if(!vis[e]){
			dfs(e);
		}
		dp[u]=(dp[u]+dp[e])%mod;
	}
}

void dfs2(int u){
	vis[u]=1;
	if(u^n) dp2[u]=1e9;
	for(auto&e:adj[u]){
		if(!vis[e]) dfs2(e);
		dp2[u]=min(dp2[u], dp2[e]+1);
	}
}

void dfs3(int u){
	vis[u]=1;
	if(u^n) dp3[u]=-1e9;
	for(auto&e:adj[u]){
		if(!vis[e]) dfs3(e);
		dp3[u]=max(dp3[u], dp3[e]+1);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int m,u,v,w; cin >> n >> m;
	while(m--){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
	}
	for(int i=1;i<=n;i++) dist[i]=1e18;
	dist[1]=0;
	pq.push({1, dist[1]});
	while(!pq.empty()){
		int ux=pq.top().ux;
		ll dx=pq.top().dx;
		pq.pop();
		if(vis[ux]) continue;
		vis[ux]=1;
		for(auto&e:g[ux]){
			if(!vis[e.first] && dist[e.first]>dx+e.second){
				dist[e.first]=dx+e.second;
				pq.push({e.first, dist[e.first]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(auto&e:g[i]){
			if(dist[i]+e.second==dist[e.first]) adj[i].push_back(e.first);
		}
	}
	dp[n]=1;
	memset(vis,0,sizeof(vis));
	dfs(1);
	cout << dist[n] << " " << dp[1] << " ";
	memset(vis,0,sizeof(vis));
	dfs2(1);
	memset(vis,0,sizeof(vis));
	dfs3(1);
	cout << dp2[1] << " " << dp3[1];
	
	return 0;
}
