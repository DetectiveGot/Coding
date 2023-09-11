#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
vector<pii> g[N], g2[N];
int dist[N], dist2[N];
bool vis[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,q,s,t,u,v,w,k; cin >> n >> m >> q >> s >> t;
	for(int i=0;i<m;i++){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g2[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++) dist[i]=1e9;
	dist[s]=0;
	pq.push({dist[s], s});
	while(!pq.empty()){
		int ux=pq.top().second, dx=pq.top().first;
		pq.pop();
		if(vis[ux]) continue;
		vis[ux]=1;
		for(auto &e:g[ux]){
			if(!vis[e.first] && dist[e.first]>dx+e.second){
				dist[e.first]=dx+e.second;
				pq.push({dist[e.first], e.first});
			}
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) dist2[i]=1e9;
	dist2[t]=0;
	pq.push({dist2[t], t});
	while(!pq.empty()){
		int ux=pq.top().second, dx=pq.top().first;
		pq.pop();
		if(vis[ux]) continue;
		vis[ux]=1;
		for(auto &e:g2[ux]){
			if(!vis[e.first] && dist2[e.first]>dx+e.second){
				dist2[e.first]=dx+e.second;
				pq.push({dist2[e.first], e.first});
			}
		}
	}
	while(q--){
		cin >> k;
		cout << dist[k]+dist2[k] << "\n";
//		deb(dist[k]); deb(dist2[k]) << endl;
	}
	
	return 0;
}
