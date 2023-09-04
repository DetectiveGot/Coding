#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
vector<int> g[N];
queue<int> q;
int vis[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	while(m--){
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		q.push(i); vis[i]=1;
		while(!q.empty()){
			int ux=q.front();
			q.pop();
			for(auto&e:g[ux]){
				if(!vis[e]){
					if(vis[ux]==1) vis[e]=2;
					else vis[e]=1;
					q.push(e);
				} else if(vis[e]==vis[ux]){
					cout << "IMPOSSIBLE\n";
					exit(0);
				}
			}
		}
	}
	for(int i=1;i<=n;i++) cout << vis[i] << " ";
	
	return 0;
}
