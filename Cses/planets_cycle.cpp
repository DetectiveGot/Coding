#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+2;
int tp[N], vis[N], dp[N];
vector<int> g[N];

void dfs(int u){
	vis[u]=1;
	for(auto&e:g[u]){
//		cout << u << " " << e << "***\n";
		if(!vis[e]) dfs(e);
		dp[u]=dp[e]+1;
	}
	vis[u]=2;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++){
		int v; cin >> v;
		g[i].push_back(v);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i);
		cout << dp[i] << " ";
	}
	
	return 0;
}
