#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 31, dx[]={1,0,-1,0},dy[]={0,-1,0,1};
char a[N][N][N];
int vis[N][N][N];
struct DATA{
	int z,x,y;
};

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int l,n,m;
	while(cin >> l >> n >> m){
		if(!(l||n||m)) break;
		queue<DATA> q;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=l;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=m;k++){
					cin >> a[i][j][k];
					if(a[i][j][k]=='S'){
						q.push({i,j,k});
						vis[i][j][k]=1;
					}
				}
			}
		}
		bool ok=true;
		while(!q.empty()){
			int z=q.front().z, x=q.front().x, y=q.front().y;
			q.pop();
			if(a[z][x][y]=='E'){
				cout << "Escaped in " << vis[z][x][y]-1 << " minute(s).\n";
				ok=false;
				break;
			}
			for(int i=0;i<4;i++){
				int vx=x+dx[i], vy=y+dy[i];
				if(z>1 && a[z-1][x][y]!='#' && !vis[z-1][x][y]){
					vis[z-1][x][y]=vis[z][x][y]+1;
					q.push({z-1,x,y});
				}
				if(z<l && a[z+1][x][y]!='#' && !vis[z+1][x][y]){
					vis[z+1][x][y]=vis[z][x][y]+1;
					q.push({z+1,x,y});
				}
				if(vx<1 || vy<0 || vx>n || vy>m) continue;
				if(a[z][vx][vy]!='#' && !vis[z][vx][vy]){
					vis[z][vx][vy]=vis[z][x][y]+1;
					q.push({z,vx,vy});
				}
			}
		}
		if(ok) cout << "Trapped!\n";
	}

	return 0;
}

