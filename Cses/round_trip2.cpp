#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
vector<int> g[N];
int vis[N], pv[N];

void dfs(int u, int p){
	vis[u]=1;
	pv[u]=p;
	for(auto&e:g[u]){
		if(!vis[e]){
			dfs(e, u);
		} else if(vis[e]==1){
			vector<int> ans={e};
			while(u^e){
				ans.push_back(u);
				u=pv[u];
			}
			ans.push_back(u);
			reverse(ans.begin(), ans.end());
			cout << ans.size() << "\n";
			for(auto&e:ans) cout << e << " ";
			exit(0);
		}
	}
	vis[u]=2;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,u,v; cin >> n >> m;
	while(m--){
		cin >> u >> v;
		g[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]) dfs(i, -1);
	cout << "IMPOSSIBLE";
	
	return 0;
}
