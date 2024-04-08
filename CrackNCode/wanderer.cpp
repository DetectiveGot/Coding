#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

const int N = 1e5+2, Q=13;
struct DATA{
	int ux,cnt,dist;
	bool operator < (const DATA &dt) const{
		return dist>dt.dist;
	}
};
int dist[N][Q];
vector<pii> g[N];
priority_queue<DATA> pq;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,q; cin >> n >> m >> q;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=q;j++)
			dist[i][j]=2e9;
	int u,v,w;
	while(m--){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=0;i<q;i++){
		dist[1][i]=0;
		pq.push({1, i, dist[1][i]});
	}
	while(!pq.empty()){
		int ux=pq.top().ux, cnt=pq.top().cnt, dx=pq.top().dist;
		pq.pop();
//		cout << ux << " " << cnt << " " << dx << endl;
		for(auto&e:g[ux]){
			int dif=min(cnt+1, q-1);
			if(dist[e.first][dif]>dx+e.second){
				dist[e.first][dif]=dx+e.second;
				pq.push({e.first, dif, dist[e.first][dif]});
			}
			if(cnt+1>=q && dist[e.first][0]>dx){
				dist[e.first][0]=dx;
				pq.push({e.first, 0, dist[e.first][0]});
			}
		}
	}
	int ans=2e9;
	for(int i=0;i<q;i++) ans=min(ans, dist[n][i]);
	cout << ans;
	
	return 0;
}
