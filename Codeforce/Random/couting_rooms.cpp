#include<bits/stdc++.h>

using namespace std;

const int N = 1002, dx[]={-1,0,1,0}, dy[]={0,1,0,-1};
bool vis[N][N];
queue<pair<int,int>> q;
char a[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,cnt=0; cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vis[i][j] || a[i][j]=='#') continue;
			cnt++;
			q.push({i,j});
			while(!q.empty()){
				int ux=q.front().first, uy=q.front().second;
				q.pop();
				for(int i=0;i<4;i++){
					int vx=ux+dx[i],vy=uy+dy[i];
					if(vx<1 || vx>n || vy<1 || vy>m) continue;
					if(!vis[vx][vy] && a[vx][vy]=='.'){
						vis[vx][vy]=1;
						q.push({vx,vy});
					}
				}
			}
		}
	}
	cout << cnt;
	
	return 0;
}
