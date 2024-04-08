#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int N = 1002, dx[]={1,0,-1,0}, dy[]={0,-1,0,1};
struct DATA{
	int ux,uy,dist;
	bool operator < (const DATA &dt) const{
		return dist>dt.dist;
	}
};
int a[N][N], dist[N][N];
bool vis[N][N];
priority_queue<DATA> pq;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dist[i][j]=2e9;
			cin >> a[i][j];
			if(i==1) dist[i][j]=a[i][j], pq.push({i,j,dist[i][j]});
		}
	}
	while(!pq.empty()){
		int ux=pq.top().ux,uy=pq.top().uy,dis=pq.top().dist;
		pq.pop();
		if(vis[ux][uy]) continue;
		vis[ux][uy]=1;
		if(ux==n){
			cout << dis;
			return 0;
		}
		for(int i=0;i<4;i++){
			int vx=ux+dx[i], vy=uy+dy[i];
			if(vx<1 || vy<1 || vx>n || vy>m) continue;
			if(!vis[vx][vy] && dist[vx][vy]>dis+a[vx][vy]){
				dist[vx][vy]=dis+a[vx][vy];
				pq.push({vx,vy,dist[vx][vy]});
			}
		}
	}
	
	return 0;
}
