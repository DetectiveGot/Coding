#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 51,dx[]={-1,-1,0,1,1,1,0,-1}, dy[]={0,1,1,1,0,-1,-1,-1};
struct DATA{
	int x,y,d;
	bool operator < (const DATA &dt) const{
		return d>dt.d;
	}
};

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m; cin >> n >> m;
	char a[n+1][m+1];
	bool vis[n+1][m+1];
	int dist[n+1][m+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	int q; cin >> q;
	while(q--){
		priority_queue<DATA> pq;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dist[i][j]=1e9, vis[i][j]=0;
		pii st,ed; cin >> st.first >> st.second >> ed.first >> ed.second;
		pq.push({st.first, st.second, dist[st.first][st.second]=0});
		int ans=0;
		while(!pq.empty()){
			int x=pq.top().x,y=pq.top().y,d=pq.top().d;
			pq.pop();
			if(vis[x][y]) continue;
			vis[x][y]=1;
			if(x==ed.first && y==ed.second){
				ans=d;
				break;
			}
			for(int i=0;i<8;i++){
				int vx=x+dx[i], vy=y+dy[i];
				if(vx<1 || vy<1 || vx>n || vy>m || vis[vx][vy]) continue;
				if(dist[vx][vy]>d+(i!=a[x][y]-'0')){
					dist[vx][vy]=d+(i!=a[x][y]-'0');
					pq.push({vx,vy,dist[vx][vy]});
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}

