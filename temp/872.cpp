#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1001;
vector<int> g[N];
bool vis[N], v2[N];
queue<int> q;
int dist[N],ds[N];

inline void dfs(int u, int s){
	v2[u]=1;
	for(auto &e:g[u]){
		if(!v2[e]) dfs(e, s);
		else if(e==s) ds[u]=1;
		ds[u]=min(ds[u], ds[e]+1);
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int qu,n,m,k,s,u,v; cin >> qu;
	while(qu--){
		cin >> n >> m >> k >> s;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=0;i<m;i++){
			cin >> u >> v;
			g[u].push_back(v);
		}
		memset(dist,0,sizeof(dist));
		memset(vis,0,sizeof(vis));
		q.push(s); vis[s]=1;
		while(!q.empty()){
			u=q.front();
			q.pop();
			for(auto &e:g[u]){
				if(vis[e]) continue;
				q.push(e);
				vis[e]=1;
				dist[e]=dist[u]+1;
			}
		}
		int ans=1e9,ans2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) ds[j]=1e9,v2[j]=0;
			dfs(i, i);
			if(ds[i]>=1e9 || !vis[i]) continue;
			int cal = dist[i]+ds[i]*(k-1);
			if(ans>cal) ans=cal, ans2=i;
		}
		if(ans>=1e9) cout << "-1\n";
		else cout << ans << " " << ans2 << "\n";
	}
	
	return 0;
}
