#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1001, lim=1, dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int vis[N][N][4][2];
char a[N][N];
struct DATA{
	int x,y,d,w;
};

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc; cin >> tc;
	while(tc--){
		int n,m; cin >> n >> m;
		pii ed;
		queue<DATA> q;
		memset(vis, 0, sizeof(vis));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> a[i][j];
				if(a[i][j]=='R'){
					for(int k=0;k<4;k++){
						vis[i][j][k][lim]=1;
						q.push({i,j,k,lim});
					}
				}
			}
		}
		bool ok=true;
		while(!q.empty()){
			int x=q.front().x,y=q.front().y,d=q.front().d,w=q.front().w;
			q.pop();
			if(a[x][y]=='D'){
				ok=false;
				cout << vis[x][y][d][w]-1 << "\n";
				break;
			}
			for(int i=0;i<4;i++){
				int vx=x+dx[i], vy=y+dy[i];
				if(vx<1 || vy<1 || vx>n || vy>m) continue;
				if(a[vx][vy]=='B') continue;
				if(i==(d+2)%4) continue;
				if(i==d && w && !vis[vx][vy][i][w-1]){
					vis[vx][vy][i][w-1]=vis[x][y][i][w]+1;
					q.push({vx,vy,i,w-1});
				}
				if(i!=d && !vis[vx][vy][i][lim]){
					vis[vx][vy][i][lim]=vis[x][y][d][w]+1;
					q.push({vx,vy,i,lim});
				}
			}
		}
		if(ok) cout << "-1\n";
	}
	
	return 0;
}

