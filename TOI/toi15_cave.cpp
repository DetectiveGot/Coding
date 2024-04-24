#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define tpi tuple<ll,ll,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2001;
vector<pii> g[N];
ll dist[N][N];
bool vis[N][N];
priority_queue<tpi, vector<tpi>, greater<tpi>> pq;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,u,v,w,s,t; cin >> n >> s >> t >> m;
	for(int i=0;i<m;i++){
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
	}
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) dist[i][j]=1e9;
	dist[s][0]=0;
	pq.emplace(dist[s][0], 0, s);
	while(!pq.empty()){
		auto [d, c, ux] = pq.top();
		pq.pop();
		if(vis[ux][c] || c+1>=n) continue;
		vis[ux][c]=1;
		for(auto &e:g[ux]){
			if(e.first==s) continue;
			if(c+1>=n && vis[e.first][c+1]) continue;
			if(dist[e.first][c+1]>d+e.second){
				dist[e.first][c+1]=d+e.second;
				pq.emplace(dist[e.first][c+1], c+1, e.first);
			}
		}
	}
	vector<int> ask;
	for(int i=1;i<n;i++){
		if(dist[t][i]>=1e9) continue;
		if(!ask.empty() && dist[t][ask.back()]<=dist[t][i]) continue;
		ask.emplace_back(i);
	}
	int tc,h; cin >> tc;
	while(tc--){
		cin >> h;
		ll ans=1e18;
		for(auto &e:ask) ans=min(ans, dist[t][e]+h*(e-1));
		cout << ans << " ";
	}

	return 0;
}
