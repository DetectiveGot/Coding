#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

const int N = 1001, mxN = 1e5+1, dx[]={1,0,-1,0}, dy[]={0,-1,0,1};
int id[N][N], pa[mxN];
bool vis[N][N];
vector<pii> v;
queue<pii> q;
set<pii> s;
struct DATA{
	int u,v,w;
	bool operator < (const DATA &dt) const{
		return w<dt.w;
	}
};
vector<DATA> g;

inline int cal(const pii &a, const pii &b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}

inline int fp(int x){
	if(pa[x]==x) return x;
	return pa[x]=fp(pa[x]);
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	int x,y;
	int idx=0;
	iota(pa, pa+n, 0);
	for(int i=0;i<n;i++){
		cin >> x >> y;
		if(!vis[x][y]){
			v.emplace_back(x,y);
			id[x][y]=idx++;
			q.push({x,y});
			vis[x][y]=1;
		}
	}
	while(!q.empty()){
		x=q.front().first, y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int vx=x+dx[i], vy=y+dy[i];
			if(vx<0 || vy<0 || vx>=1000 || vy>=1000) continue;
			if(!vis[vx][vy]){
				vis[vx][vy]=1;
				id[vx][vy]=id[x][y];
				q.push({vx,vy});
			}
		}
	}
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			if(i && id[i-1][j]^id[i][j]){
				int d1=min(id[i-1][j], id[i][j]), d2=max(id[i-1][j], id[i][j]);
				s.insert({d1, d2});
			}
			if(j && id[i][j-1]^id[i][j]){
				int d1=min(id[i][j-1], id[i][j]), d2=max(id[i][j-1], id[i][j]);
				s.insert({d1, d2});
			}
		}
	}
	int pu,pv,w,ans=0;
	for(auto &e:s){
		w=cal(v[e.first], v[e.second]);
		g.push_back({e.first, e.second, w});
	}
	sort(g.begin(), g.end());
	for(auto &e:g){
		pu=fp(e.u), pv=fp(e.v), w=e.w;
		if(pu==pv) continue;
		pa[pv]=pu;
		ans+=e.w;
	}
	/*for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cout << id[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << ans;
	
	return 0;
}
