#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

const int N = 1e5+2;
vector<pii> g[N];
ll up[N][30], tin[N], cnt=1, dist[N], tout[N];

void dfs(int u, int p){
  up[u][0]=p;
  tin[u]=cnt++;
  for(int i=1;i<=25;i++) up[u][i]=up[up[u][i-1]][i-1];
  for(auto&e:g[u]){
    if(e.first==p) continue;
    dist[e.first]=dist[u]+e.second;
    dfs(e.first, u);
  }
  tout[u]=cnt++;
}

bool ances(int u, int v){
  return tin[u]<=tin[v] && tout[u]>=tout[v];
}

int lca(int u, int v){
  if(ances(u,v)) return u;
  if(ances(v,u)) return v;
  for(int i=25;i>=0;--i){
    if(!ances(up[u][i], v)){
      u=up[u][i];
    }
  }
  return up[u][0];
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  for(int i=1;i<n;i++){
    ll v,w; cin >> v >> w;
    g[i].push_back({v,w});
    g[v].push_back({i,w});
  }
  dfs(0, 0);
  int q,u,v; cin >> q;
  while(q--){
    cin >> u >> v;
    cout << dist[u]+dist[v]-2*dist[lca(u,v)] << "\n";
  }

  return 0;
}
