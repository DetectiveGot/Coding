#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

const int N = 2e5+2;
struct TYPE{
	int v, w, type;
};
int dist[N];
int tp[N];
bool vis[N];
vector<TYPE> g[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void solve(){
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++){
		vis[i]=0;
		tp[i]=0;
		dist[i]=2e9;
		g[i].clear();
	}
	while(m--){
		int u,v,w; cin >> u >> v >> w;
		g[u].push_back({v,w,1});
		g[v].push_back({u,w,2});
	}
	dist[1]=0;
	pq.push({dist[1], 1});
	while(!pq.empty()){
		int ux=pq.top().second, dx=pq.top().first;
		pq.pop();
		if(vis[ux]) continue;
		vis[ux]=1;
//		cout << ux << " " << dx << "*******\n";
		for(auto&e:g[ux]){
			if(!vis[e.v]){
				dist[e.v]=e.w;
				tp[e.v]=e.type;
				pq.push({dist[e.v], e.v});
			}
		}
	}
	int mn=INT_MAX;
	bool req=false;
	for(int i=1;i<=n;i++){
		if(tp[i]==2) mn=min(mn, dist[i]), req=true;
		if(!vis[i]){
//			cout << i << "****\n";
			cout << "-1\n";
			return;
		}
	}
	if(req) cout << mn << "\n";
	else cout << "0\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}
