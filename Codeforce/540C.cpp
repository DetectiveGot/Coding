#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int N = 502, dx[]={1,0,-1,0}, dy[]={0,-1,0,1};
char a[N][N];
bool vis[N][N];
queue<pii> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	pii st, ed; cin >> st.first >> st.second >> ed.first >> ed.second;
	vis[st.first][st.second]=1;
	q.push(st);
	while(!q.empty()){
		int ux=q.front().first, uy=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int vx=ux+dx[i], vy=uy+dy[i];
			if(vx<1 || vy<1 || vx>n || vy>m) continue;
			if(!vis[vx][vy] && a[vx][vy]=='.'){
				q.push({vx,vy});
				vis[vx][vy]=1;
			} else if(vx==ed.first && vy==ed.second){
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	
	return 0;
}
