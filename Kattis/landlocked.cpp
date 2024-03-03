#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1001;
int dist[N][N], ans[26];
char a[N][N];
bool vis[N][N];
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
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			dist[i][j]=1e9;
			if(a[i][j]=='W') pq.push({i,j,0}), dist[i][j]=0;
		}
	}
	for(int i=0;i<26;i++) ans[i]=1e9;
	while(!pq.empty()){
		int x=pq.top().x, y=pq.top().y, d=pq.top().d;
		pq.pop();
		if(vis[x][y]) continue;
		vis[x][y]=1;
		ans[a[x][y]-'A']=min(ans[a[x][y]-'A'], d);
		for(int i=-1;i<=1;i++){
			for(int j=-1;j<=1;j++){
				if(i==0 && j==0) continue;
				int vx=x+i, vy=y+j;
				if(vx<1 || vy<1 || vx>n || vy>m) continue;
				if(!vis[vx][vy] && dist[vx][vy]>d+(a[x][y]!=a[vx][vy])){
					dist[vx][vy]=d+(a[x][y]!=a[vx][vy]);
					pq.push({vx,vy, dist[vx][vy]});
				}
			}
		}
	}
	for(int i=0;i<26;i++) if(i!='W'-'A' && ans[i]!=1e9) cout << char(i+'A') << " " << ans[i]-1 << "\n";

	return 0;
}

