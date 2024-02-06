#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 401, dx[]={1,0,-1,0},dy[]={0,-1,0,1};
char a[N][N];
bool vis[N][N];
int dist[N][N];
struct DATA{
	int x,y,d;
	bool operator < (const DATA &dt) const{
		return d>dt.d;
	}
};
priority_queue<DATA> pq;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m; cin >> n >> m;
	memset(dist, 0x3f, sizeof(dist));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			if(i==1 || j==1 || i==n || j==m)
				if(a[i][j]=='D') pq.push({i,j,dist[i][j]=0});
		}
	}
	pii ed; cin >> ed.first >> ed.second;
	while(!pq.empty()){
		int x=pq.top().x,y=pq.top().y,d=pq.top().d;
		pq.pop();
		if(vis[x][y]) continue;
		vis[x][y]=1;
		if(x==ed.first && y==ed.second){
			cout << dist[x][y];
			return 0;
		}
		for(int i=0;i<4;i++){
			int vx=x+dx[i], vy=y+dy[i];
			if(vx<1 || vy<1 || vx>n || vy>m || a[vx][vy]=='#' || vis[vx][vy]) continue;
			int w=a[vx][vy]=='c';
			if(dist[vx][vy]>d+w){
				dist[vx][vy]=d+w;
				pq.push({vx,vy,dist[vx][vy]});
			}
		}
	}

	return 0;
}

