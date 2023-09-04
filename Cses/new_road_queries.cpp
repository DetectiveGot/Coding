#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;
const int N = 2e5+2;
int dep[N], up[N][20], pa[N], day[N][20];
struct DATA{
  int u,v,cnt;
};
vector<pii> gr[N];
bool vis[N];

int fp(int &x){
  if(pa[x]==x) return x;
  return pa[x]=fp(pa[x]);
}

void dfs(int u, int p){
  vis[u]=1;
  up[u][0]=p;
  for(int i=1;i<=17;i++){
    up[u][i]=up[up[u][i-1]][i-1];
    day[u][i]=max(day[u][i-1], day[up[u][i-1]][i-1]);
  }
  for(auto&e:gr[u]){
    if(e.first==p) continue;
    day[e.first][0]=e.second;
    dep[e.first]=dep[u]+1;
    dfs(e.first, u);
  }
}

int lca(int u, int v){
	int ans=0;
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=17;i>=0;--i){
		if(dep[up[u][i]]>=dep[v]){
			ans=max(ans, day[u][i]);
			u=up[u][i];
		}
	}
	if(u==v) return ans;
	for(int i=17;i>=0;--i){
		if(up[u][i]==up[v][i]) continue;
		ans=max({ans, day[u][i], day[v][i]});
		u=up[u][i];
		v=up[v][i];
	}
	ans=max({ans, day[u][0], day[v][0]});
	return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,q,u,v,pu,pv; cin >> n >> m >> q;
  iota(pa+1, pa+n+1, 1);
  for(int i=1;i<=m;i++){
    cin >> u >> v;
    pu=fp(u), pv=fp(v);
    if(pu==pv) continue;
    pa[pv]=pu;
    gr[u].push_back({v,i});
    gr[v].push_back({u,i});
  }
  for(int i=1;i<=n;i++){
    if(pa[i]!=i) continue;
    dfs(i,i);
  }
  while(q--){
    cin >> u >> v;
    if(fp(u)^fp(v)) cout << -1 << "\n";
    else cout << lca(u,v) << "\n";
  }

  return 0;
}
