#include<bits/stdc++.h>

using namespace std;

const int N = 102, dx[]={1,1,0,-1,-1,-1,0,1}, dy[]={0,-1,-1,-1,0,1,1,1};
bool vis[3][N], ok=false;
int n;

void dfs(int ux, int uy){
	vis[ux][uy]=1;
	if(ux==2 && uy==n){
		ok=1;
		return;
	}
	for(int i=0;i<8;i++){
		int vx=ux+dx[i], vy=uy+dy[i];
		if(vx<1 || vy<1 || vx>2 || vy>n) continue;
		if(!vis[vx][vy]){
			dfs(vx,vy);
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=2;i++){
			string s; cin >> s;
			for(int j=1;j<=n;j++){
				if(s[j-1]=='1') vis[i][j]=1;
				else vis[i][j]=0;
			}
		}
		dfs(1,1);
		if(ok) cout << "YES\n";
		else cout << "NO\n";
		ok=0;
	}
	
	return 0;
}
