#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 401, dx[]={1,0,-1,0}, dy[]={0,-1,0,1};
bool vis[N][N], ban[N][N];
vector<pii> v;
queue<pii> q;
vector<int> ans;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,k,x,y,cnt=0; cin >> n >> m >> k;
	for(int i=0;i<k;i++){
		cin >> x >> y;
		ban[x][y]=1;
		v.push_back({x,y});
	}
	for(int i=0;i<n;i++){
		if(!ban[i][0]){
			vis[i][0]=1;
			q.push({i,0});
		}
		if(!ban[i][m-1]){
			vis[i][m-1]=1;
			q.push({i, m-1});
		}
	}
	for(int i=1;i<m-1;i++){
		if(!ban[0][i]){
			vis[0][i]=1;
			q.push({0,i});
		}
		if(!ban[n-1][i]){
			vis[n-1][i]=1;
			q.push({n-1,i});
		}
	}
	while(!q.empty()){
		int ux=q.front().first, uy=q.front().second;
		q.pop();
		cnt++;
		for(int i=0;i<4;i++){
			int vx=ux+dx[i], vy=uy+dy[i];
			if(vx<0 || vy<0 || vx>=n || vy>=m || ban[vx][vy] || vis[vx][vy]) continue;
			q.push({vx,vy});
			vis[vx][vy]=1;
		}
	}
	reverse(v.begin(), v.end());
	for(auto &e:v){
		x=e.first, y=e.second;
		ban[x][y]=0;
		ans.push_back(cnt);
		for(int i=0;i<4;i++){
			int vx=x+dx[i], vy=y+dy[i];
			if(vx<0 || vy<0 || vx>=n || vy>=m || vis[vx][vy]){
				q.push({x,y});
				vis[x][y]=1;
				break;
			}
		}
		while(!q.empty()){
			int ux=q.front().first, uy=q.front().second;
			q.pop();
			cnt++;
			for(int i=0;i<4;i++){
				int vx=ux+dx[i], vy=uy+dy[i];
				if(vx<0 || vy<0 || vx>=n || vy>=m || vis[vx][vy] || ban[vx][vy]) continue;
				q.push({vx,vy});
				vis[vx][vy]=1;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	for(auto&e:ans) cout << e << "\n";
	
	return 0;
}
