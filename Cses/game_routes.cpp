#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+2, mod = 1e9+7;
vector<int> g[N];
bool vis[N];
int dp[N];

void dfs(int u){
	vis[u]=1;
	for(auto&e:g[u]){
		if(!vis[e]){
			dfs(e);
		}
		dp[u]=(dp[u]+dp[e])%mod;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,u,v; cin >> n >> m;
	while(m--){
		cin >> u >> v;
		g[u].push_back(v);
	}
	dp[n]=1;
	dfs(1);
	cout << dp[1];
	
	return 0;
}
