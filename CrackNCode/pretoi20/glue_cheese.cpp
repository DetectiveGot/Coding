#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define tpi tuple<ll,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1001, dx[]={1,0,-1,0}, dy[]={0,-1,0,1};
ll dist[N][N], dist2[N][N], a[N][N];
bool vis[N][N], vis2[N][N];
priority_queue<tpi, vector<tpi>, greater<tpi>> pq;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0); cout.tie(0);
	int n,m,sx,sy; cin >> n >> m >> sx >> sy;
	vector<pii> exit{{1,1}, {1, m}, {n, 1}, {n, m}};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			dist[i][j]=dist2[i][j]=1e18;
		}
	}
	pq.emplace(dist[sx][sy]=0, sx, sy);
	while(!pq.empty()){
		auto [d, x, y] = pq.top();
		pq.pop();
		if(vis[x][y]) continue;
		vis[x][y]=1;
		for(int i=0;i<4;i++){
			int vx = x+dx[i], vy = y+dy[i];
			if(vx<1 || vy<1 || vx>n || vy>m || vis[vx][vy]) continue;
			if(dist[vx][vy]>d+a[vx][vy]){
				dist[vx][vy]=d+a[vx][vy];
				pq.emplace(dist[vx][vy], vx,vy);
			}
		}
	}
	for(auto &w:exit) pq.emplace(dist2[w.first][w.second]=a[w.first][w.second], w.first, w.second);
	while(!pq.empty()){
			auto [d, x, y] = pq.top();
			pq.pop();
			if(vis2[x][y]) continue;
			vis2[x][y]=1;
			for(int i=0;i<4;i++){
				int vx = x+dx[i], vy = y+dy[i];
				if(vx<1 || vy<1 || vx>n || vy>m || vis2[vx][vy]) continue;
				if(dist2[vx][vy]>d+a[vx][vy]){
					dist2[vx][vy]=d+a[vx][vy];
					pq.emplace(dist2[vx][vy], vx, vy);
				}
			}
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout << dist[i][j]+dist2[sx][sy] << " ";
		}
		cout << "\n";
	}

	return 0;
}
