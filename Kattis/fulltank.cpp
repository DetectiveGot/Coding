#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1001, F = 101;
int p[N], dist[N][F];
bool vis[N][F];
vector<pii> g[N];
struct DATA{
	int u,d,fl;
	bool operator < (const DATA &dt) const{
		return d>dt.d;
	}
};

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,u,v,w; cin >> n >> m;
	for(int i=0;i<n;i++) cin >> p[i];
	for(int i=0;i<m;i++){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	int q,st,ed,c; cin >> q;
	while(q--){
		cin >> c >> st >> ed;
		priority_queue<DATA> pq;
		for(int i=0;i<n;i++) for(int j=0;j<=c;j++) dist[i][j]=1e9, vis[i][j]=0;
		pq.push({st, dist[st][0]=0, 0});
		int ans=-1;
		while(!pq.empty()){
			int ux=pq.top().u, d=pq.top().d, fl = pq.top().fl;
			pq.pop();
			if(ux==ed){
				ans=d;
				break;
			}
			if(vis[ux][fl]) continue;
			vis[ux][fl]=1;
			for(int i=fl;i<=c;i++) dist[ux][i]=min(dist[ux][i], d+(i-fl)*p[ux]);
			for(auto &e:g[ux]){
				if(fl>=e.second && !vis[e.first][fl-e.second] && dist[e.first][fl-e.second]>dist[ux][fl]){
					dist[e.first][fl-e.second]=dist[ux][fl];
					pq.push({e.first, dist[e.first][fl-e.second], fl-e.second});
				}
				if(fl+1<=c && !vis[ux][fl+1]) pq.push({ux, dist[ux][fl+1], fl+1});
			}
		}
		if(ans==-1) cout << "impossible\n";
		else cout << ans << "\n";
	}

	return 0;
}

