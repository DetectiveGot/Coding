#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+1;
vector<int> g[N];
int vis[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int t,n,m,u,v; cin >> t;
	while(t--){
		queue<int> q;
		cin >> n >> m;
		bool ok=true;
		for(int i=1;i<=n;i++){
			g[i].clear();
			vis[i]=-1;
		}
		for(int i=0;i<m;i++){
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		q.push(1); vis[1]=0;
		while(!q.empty()){
			u=q.front();
			q.pop();
			for(auto&e:g[u]){
				if(vis[e]==-1){
					vis[e]=vis[u]^1;
					q.push(e);
				} else if(vis[e]==vis[u]){
					ok=false;
            	}
        	}
        }
		if(ok) cout << "yes\n";
		else cout << "no\n";
	}
	
	return 0;
}
