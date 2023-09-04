#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+2, dx[]={-1,0,1}, dy[]={0,1,0};
char a[3][N];
int n, prvi,prvj;
bool vis[3][N];

int dfs(int x, int y, int cnt){
	vis[x][y]=1;
	cnt++;
	for(int i=0;i<3;i++){
		int vx=x+dx[i], vy=y+dy[i];
		if(vx<1 || vx>2 || vy<1 || vy>n || vx==abs(prvi) || vy==abs(prvj)) continue;
		if(!vis[vx][vy] && a[vx][vy]=='B'){
			prvi=x,prvj=y;
			cnt=dfs(vx,vy,cnt);
		}
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		bool ok=false;
		cin >> n;
		int c=0;
		for(int i=1;i<=2;i++){
			for(int j=1;j<=n;j++){
				cin >> a[i][j];
				if(a[i][j]=='B') c++;
			}
		}
		if(a[1][1]=='B') cout << (dfs(1,1,0)) << "*2*\n";
		if(a[2][1]=='B') cout << (dfs(2,1,0)) << "*1*\n";
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
/*
6
3
WBB
BBW
1
B
B
5
BWBWB
BBBBB
2
BW
WB
5
BBBBW
BWBBB
6
BWBBWB
BBBBBB

*/
