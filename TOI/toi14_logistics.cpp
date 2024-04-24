#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define tpi tuple<int,int,int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 101, F = 101;
int p[N], dist[N][F][2];
bool vis[N][F][2];
vector<pii> g[N];
priority_queue<tpi, vector<tpi>, greater<tpi>> pq;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,s,d,f,m,u,v,w; cin >> n;
	for(int i=1;i<=n;i++) cin >> p[i];
	cin >> s >> d >> f >> m;
	for(int i=0;i<m;i++){
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	memset(dist, 0x3f, sizeof(dist));
	pq.emplace(dist[s][0][0]=0, s, 0, 0);
	while(!pq.empty()){
		auto [dx, ux, fl, us] = pq.top();
		pq.pop();
		if(vis[ux][fl][us]) continue;
		vis[ux][fl][us]=1;
		for(int i=fl;i<=f;i++) if(!us && !vis[ux][i][1] && dist[ux][i][1]>dist[ux][fl][us]) dist[ux][i][1]=dx, pq.emplace(dist[ux][i][1], ux, i, 1);
		if(fl+1<=f && !vis[ux][fl+1][us] &&  dist[ux][fl+1][us]>dx+p[ux]) dist[ux][fl+1][us]=dx+p[ux], pq.emplace(dist[ux][fl+1][us], ux, fl+1, us);
		for(auto &e:g[ux]){
			if(fl>=e.second && !vis[e.first][fl-e.second][us] && dist[e.first][fl-e.second][us]>dx){
				dist[e.first][fl-e.second][us]=dx;
				pq.emplace(dist[e.first][fl-e.second][us], e.first, fl-e.second, us);
			}
		}
	}
	cout << min(dist[d][f][0], dist[d][f][1]);

	return 0;
}
