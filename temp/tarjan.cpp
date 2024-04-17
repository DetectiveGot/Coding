#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+2;
vector<int> g[N];
int dfn[N], low[N], id=0;
bool in[N];
stack<int> scc;

void dfs(int u){
	dfn[u]=low[u]=++id;
	in[u]=1;
	scc.push(u);
	for(auto&e:g[u]){
		if(!dfn[e]){
			dfs(e);
			low[u]=min(low[u], low[e]);
		} else if(in[e]) low[u]=min(low[u], dfn[e]);
	}
	if(low[u]==dfn[u]){
		cout << "SCC: ";
		while(1){
			int v=scc.top();
			scc.pop();
			in[v]=0;
			cout << v-1 << " ";
			if(u==v) break;
		}
		cout << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	while(m--){
		int u,v; cin >> u >> v;
		g[u].push_back(v);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i);
	
	return 0;
}
