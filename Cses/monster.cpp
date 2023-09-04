#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int N = 1002, dx[]={1,0,-1,0},dy[]={0,-1,0,1};
char a[N][N], prv[N][N];
bool vis1[N][N], vis2[N][N];
int dist1[N][N], dist2[N][N];
queue<pii> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	pii st;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			if(a[i][j]=='M') q.push({i,j}), vis1[i][j]=1;
			else if(a[i][j]=='A') st={i,j};
		}
	}
	while(!q.empty()){
		int ux=q.front().first, uy=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int vx=ux+dx[i], vy=uy+dy[i];
			if(vx<1 || vy<1 || vx>n || vy>m || a[vx][vy]=='#') continue;
			if(!vis1[vx][vy]){
				dist1[vx][vy]=dist1[ux][uy]+1;
				vis1[vx][vy]=1;
				q.push({vx,vy});
			}
		}
	}
	q.push(st);
	vis2[st.first][st.second]=1;
	while(!q.empty()){
		int ux=q.front().first, uy=q.front().second;
		q.pop();
		if(ux==n || ux==1 || uy==m || uy==1){
			cout << "YES\n" << dist2[ux][uy] << "\n";
			string ans="";
			while(st.first^ux || st.second^uy){
				ans+=prv[ux][uy];
				if(prv[ux][uy]=='D') ux--;
				else if(prv[ux][uy]=='L') uy++;
				else if(prv[ux][uy]=='R') uy--;
				else if(prv[ux][uy]=='U') ux++;
			}
			reverse(ans.begin(), ans.end());
			cout << ans;
			return 0;
		}
		for(int i=0;i<4;i++){
			int vx=ux+dx[i], vy=uy+dy[i];
			if(vx<1 || vy<1 || vx>n || vy>m || a[vx][vy]=='#') continue;
			if(!vis2[vx][vy] && (!vis1[vx][vy] || dist2[ux][uy]+1<dist1[vx][vy])){
				dist2[vx][vy]=dist2[ux][uy]+1;
				vis2[vx][vy]=1;
				q.push({vx,vy});
				if(i==0) prv[vx][vy]='D';
				else if(i==1) prv[vx][vy]='L';
				else if(i==2) prv[vx][vy]='U';
				else if(i==3) prv[vx][vy]='R';
			}
		}
	}
	cout << "NO\n";
	
	return 0;
}
