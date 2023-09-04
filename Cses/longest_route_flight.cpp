#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
int dp[N];
vector<int> g[N];
int prv[N],n;
bool vis[N];

void dfs(int u){
	vis[u]=1;
	if(u==n) dp[u]=1;
	else dp[u]=-1e9;
	for(auto&e:g[u]){
		if(!vis[e]){
			dfs(e);
		}
		if(dp[e]+1>dp[u]){
			dp[u]=dp[e]+1;
			prv[u]=e;
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int m,u,v; cin >> n >> m;
	while(m--){
		cin >> u >> v;
		g[u].push_back(v);
	}
	dfs(1);
	if(dp[1]<=0){
		cout << "IMPOSSIBLE";
		return 0;
	}
	vector<int> ans;
	int i=1;
	while(i^n){
		ans.push_back(i);
		i=prv[i];
	}
	ans.push_back(i);
	cout << ans.size() << "\n";
	for(auto&e:ans) cout << e << " ";
	
	return 0;
}
