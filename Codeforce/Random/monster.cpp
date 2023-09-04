#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int N = 1002, dx[]={-1,0,1,0}, dy[]={0,1,0,-1};
char a[N][N];
vector<pii> mol;
queue<pii> q,qm;
char vis[N][N];
bool vism[N][N];

void m_move(){
	for(auto&m:mol){
		int ux=m.first, uy=m.second;
		for(int i=0;i<4;i++){
			int vx=ux+dx[i], vy=vy+dy[i];
			if(vx<1 || vx>n || vy<1 || vy>m) continue;
			if(!vism[vx][vy] && a[vx][vy]!='#'){
				vism[vx][vy]=1;
				qm.push({vx,vy});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,sti,stj; cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i];
			if(a[i]=='M') qm.push({i,j}),vism[i][j]=1;
			if(a[i]=='A') sti=i,stj=j;
		}
	}
	q.push({sti,stj}); vis[sti][stj]=1;
	while(!q.empty()){
		int ux=q.front().first, uy=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int vx=ux+dx[i], vy=uy+dy[i];
			if(vx<1 || vx>n || vy<1 || vy>m) continue;
			if((!vis[vx][vy] || !vism[vx][vy]) && (a[vx][vy]!='M' || a[vx][vy]!='#')){
				q.push({vx,vy});
				vis[vx][vy]='M';
			}
		}
		m_move();
	}
	
	return 0;
}
/*
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######
*/
