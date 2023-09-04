#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
vector<int> g[N],ans;
bool vis[N];
stack<int> path;
int prv=1;

void dfs(int u){
	vis[u]=1;
	path.push(u);
//	cout << u << "\n";
	for(auto&e:g[u]){
		if(prv==e) continue;
		if(!vis[e]){
			prv=u;
			dfs(e);
		} else if(vis[e] && !path.empty()){
//			cout << "DEBUG: ";
			path.push(e);
			do{
				ans.push_back(path.top());
				path.pop();
			} while(path.top()!=e);
			ans.push_back(e);
			cout << ans.size() << "\n";
			for(auto&e:ans) cout << e << " ";
			exit(0);
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	while(m--){
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
//	path.push(1);
	cout << "IMPOSSIBLE\n";
	
	return 0;
}
