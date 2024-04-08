#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

const int N = 1e5+2;
int dist[N];
bool vis[N];
struct DATA{
	int ux, dx;
	bool operator < (const DATA &dt) const{
		return dx>dt.dx;
	}
};
struct A{
	int v,w,f;
};
vector<A> g[N];
priority_queue<DATA> pq;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	int u,v,w,f;
	for(int i=1;i<=n;i++) dist[i]=1e9;
	while(m--){
		cin >> u >> v >> w >> f;
		g[u].push_back({v,w,f});
		g[v].push_back({u,w,f});
	}
	dist[1]=0;
	pq.push({1, dist[1]});
	while(!pq.empty()){
		int ux=pq.top().ux, dx=pq.top().dx;
		pq.pop();
		if(vis[ux]) continue;
		vis[ux]=1;
		for(auto&e:g[ux]){
			if(!vis[e.v] && dist[e.v]>dx+e.w+(e.w/e.f)*e.f){
				dist[e.v]=e.w+dx+(e.w/e.f)*e.f;
				pq.push({e.v, dist[e.v]});
			}
		}
	}
	cout << dist[n];
	
	return 0;
}
