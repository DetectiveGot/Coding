#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1001, dx[]={-1,0,1,0},dy[]={0,1,0,-1};
char a[N][N];
bool vis[N][N];
vector<pii> g[2];

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc; cin >> tc;
	while(tc--) {
		int n,m;
		cin >> m >> n;
		memset(vis, 0, sizeof(vis));
		g[0].clear();
		g[1].clear();
		int x,y;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin >> a[i][j];
				if(a[i][j]=='G') x=i,y=j, vis[i][j]=1;
				else if(a[i][j]=='M') g[0].push_back({i,j});
			}
		}
		int nw=1,nx,ny,ans=0;
		while(true) {
			nw^=1;
			nx=x,ny=y;
			bool walk=false,die=false;
			for(int d=0; d<4; d++) {
				int vx=x+dx[d], vy=y+dy[d];
				if(vx<1 || vy<1 || vx>n || vy>m || vis[vx][vy] || a[vx][vy]=='x') continue;
				if(a[vx][vy]=='R') {
					nx=vx,ny=vy;
					++ans;
					a[x][y]='.';
					walk=true;
					break;
				}
			}
			if(!walk) {
				for(int d=0; d<4; d++) {
					int vx=x+dx[d], vy=y+dy[d];
					if(vx<1 || vy<1 || vx>n || vy>m || vis[vx][vy]) continue;
					nx=vx,ny=vy;
					a[x][y]='.';
					walk=true;
					break;
				}
			}
			vis[nx][ny]=1;
			if(a[nx][ny]=='M'){
				die=true;
				break;
			}
			a[nx][ny]='G';
			x=nx,y=ny;
			for(auto &e:g[nw]) {
				for(int i=0; i<4; i++) {
					int vx=e.first+dx[i], vy=e.second+dy[i];
					if(vx<1 || vy<1 || vx>n || vy>m || a[vx][vy]=='R' || a[vx][vy]=='M' || vis[vx][vy]) continue;
					a[vx][vy]='M';
					g[nw^1].push_back({vx,vy});
				}
			}
			g[nw].clear();
			for(int i=x; i>=1; --i) {
				if(a[i][y]=='R') break;
				if(a[i][y]=='M') {
					die=true;
					break;
				}
			}
			for(int i=x; i<=n && !die; ++i) {
				if(a[i][y]=='R') break;
				if(a[i][y]=='M') {
					die=true;
					break;
				}
			}
			for(int i=y; i<=m && !die; ++i) {
				if(a[x][i]=='R') break;
				if(a[x][i]=='M') {
					die=true;
					break;
				}
			}
			for(int i=y; i>=1 && !die; --i) {
				if(a[x][i]=='R') break;
				if(a[x][i]=='M') {
					die=true;
					break;
				}
			}
			if(die) break;
		}
		cout << ans << "\n";
	}

	return 0;
}
