#include<bits/stdc++.h>

using namespace std;

const int N = 1002, dx[]={-1,0,1,0}, dy[]={0,1,0,-1};
char a[N][N];
char vis[N][N];
int sti,stj,n,m;
queue<pair<int,int>> q;
map<pair<int,int>, char> mp;
string ans="";

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	mp[{-1,0}]='U', mp[{0,1}]='R', mp[{1,0}]='D', mp[{0,-1}]='L';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			if(a[i][j]=='A') sti=i, stj=j;
		}
	}
	q.push({sti, stj});
	while(!q.empty()){
		int ux=q.front().first, uy=q.front().second;
		q.pop();
		if(a[ux][uy]=='B'){
			do{
//				cout << ux << " " << uy << endl;
				ans+=vis[ux][uy];
				if(vis[ux][uy]=='L') ++uy;
				else if(vis[ux][uy]=='R') --uy;
				else if(vis[ux][uy]=='U') ++ux;
				else if(vis[ux][uy]=='D') --ux;
			} while(a[ux][uy]!='A');
			reverse(ans.begin(), ans.end());
			cout << "YES\n" << ans.size() << "\n" << ans;
			exit(0);
		}
		for(int i=0;i<4;i++){
			int vx=ux+dx[i], vy=uy+dy[i];
			if(vx<1 || vx>n || vy<1 || vy>m) continue;
			if(!vis[vx][vy]&& a[vx][vy]!='#'){
				q.push({vx,vy});
				if(mp[{dx[i], dy[i]}]=='L') vis[vx][vy]='L';
				else if(mp[{dx[i], dy[i]}]=='R') vis[vx][vy]='R';
				else if(mp[{dx[i], dy[i]}]=='U') vis[vx][vy]='U';
				else if(mp[{dx[i], dy[i]}]=='D') vis[vx][vy]='D';
			}
		}
	}
	cout << "NO\n";
	
	return 0;
}
