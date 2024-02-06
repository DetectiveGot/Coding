#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 251, dx[]={1,0,-1,0}, dy[]={0,-1,0,1};
int a[N][N],n,m,xx,yy,mn=1e9;
bool vis[N][N];
vector<int> vec;
vector<vector<int>> ans;

inline void dfs(int x, int y){
	vis[x][y]=1;
	if(x==xx && y==yy){
		if(mn>vec.size()){
			mn=vec.size();
			ans.clear();
			ans.push_back(vec);
		} else if(mn==vec.size()) ans.push_back(vec);
		return;
	}
	for(int i=0;i<4;i++){
		int vx=x+dx[i], vy=y+dy[i];
		int vxx=vx+dx[i], vyy=vy+dy[i];
		if(vxx>n || vyy>m || vxx<1 || vyy<1 || vis[vxx][vyy] || a[vxx][vyy]==-2) continue;
		if(a[vx][vy]!=a[vxx][vyy]) continue;
		swap(a[vxx][vyy], a[x][y]);
		vec.push_back(a[x][y]);
		dfs(vxx,vyy);
		vec.pop_back();
		swap(a[vxx][vyy], a[x][y]);
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> n >> m;
	int st,ed;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			if(a[i][j]==-1) st=i,ed=j;
		}
	}
	cin >> xx >> yy;
	dfs(st,ed);
	sort(ans.begin(), ans.end());
	if(!ans.empty()) for(auto &e:*ans.begin()) cout << e << " ";
	else cout << "impossible";

	return 0;
}

