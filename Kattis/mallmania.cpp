#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2001, dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int vis[N][N],dist[N][N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,x,y;
	while(cin >> n && n!=0){
		queue<pii> q;
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) vis[i][j]=dist[i][j]=0;
		for(int i=0;i<n;i++){
			cin >> x >> y;
			q.push({x,y}); vis[x][y]=1;
		}
		cin >> m;
		for(int i=0;i<m;i++){
			cin >> x >> y;
			vis[x][y]=2;
		}
		bool ok=false;
		int ans=0;
		while(!q.empty()){
			int x=q.front().first, y=q.front().second;
			q.pop();
			for(int i=0;i<4;i++){
				int vx=x+dx[i], vy=y+dy[i];
				if(vx<0 || vy<0 || vx>=N || vy>=N || vis[vx][vy]==1) continue;
				dist[vx][vy]=dist[x][y]+1;
				if(vis[vx][vy]==2){
					ans=dist[vx][vy];
					ok=true;
					break;
				}
				q.push({vx,vy});
				vis[vx][vy]=1;
			}
			if(ok) break;
		}
		cout << ans << "\n";
	}

	return 0;
}

