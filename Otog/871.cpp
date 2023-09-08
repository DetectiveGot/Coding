#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;
const int N = 50001, K = 21;
bool ch[N], vis[N][K];
int dist[N][K];
struct DATA{
	int ux,dx,cnt;
	bool operator < (const DATA &dt) const{
		return dx>dt.dx;
	}
};
priority_queue<DATA> pq;
vector<pii> g[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,p,k,u,v,w,s,t; cin >> n >> m >> p >> k;
	for(int i=0;i<m;i++){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=0;i<p;i++){
		cin >> t;
		ch[t]=1;
	}
	cin >> s;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			dist[i][j]=1e9;
	dist[s][0]=0;
	pq.push({s, dist[s][0], 0});
	while(!pq.empty()){
		int ux=pq.top().ux, dx=pq.top().dx, cnt=pq.top().cnt;
		pq.pop();
		if(vis[ux][cnt]) continue;
		vis[ux][cnt]=1;
		for(auto &e:g[ux]){
			if(ch[e.first] && !vis[e.first][cnt+1] && dist[e.first][cnt+1]>dx+e.second){
				dist[e.first][cnt+1]=dx+e.second;
				pq.push({e.first, dist[e.first][cnt+1], cnt+1});
			}
			if(!vis[e.first][cnt] && dist[e.first][cnt]>dx+e.second){
				dist[e.first][cnt]=dx+e.second;
				pq.push({e.first, dist[e.first][cnt], cnt});
			}
		}
	}
	if(!vis[s][k]) cout << "NO FOOD :(";
	else cout << dist[s][k];
	
	return 0;
}
