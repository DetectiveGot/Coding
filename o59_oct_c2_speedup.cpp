#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

const int mxN = 8e4+2, mxQ = 9;
int dist[mxN][mxQ];
bool dist[mxN][mxQ], ch[N];
struct DATA{
  int ux, prv, po;
  ll dist;
  bool operator < (const DATA &dt) const{
    return dist>dt.dist;
  }
};
vector<pii> g[N];
priority_queue<DATA> pq;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,l,q,u,v,w; cin >> n >> m >> l >> q;
  for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
          dist[i][j]=1e18;
  while(m--){
    cin >> u >> v >> w;
    g[u].push_back({v,w});
    g[v].push_back({u,w});
  }
  for(int i=0;i<l;i++){
    int t; cin >> t;
    ch[t]=1;
  }
  dist[1][0]=0;
  pq.push({1,0,0,dist[1][0]});
  while(!pq.empty()){
    int ux=pq.top().ux, prv=pq.top().prv, po=pq.top().po;
    ll dx=pq.top().dx, spd=1<<po;
    pq.pop();
    if(vis[ux][po]) continue;
    vis[ux][po]=1;
    for(auto&e:g[ux]){
      if(!vis[e.first][po] && dist[e.first][po]>dx+e.second/spd){
        dist[e.first][po]=dx+e.second/spd;
        pq.push({e.first, -1, po, dist[e.first][po]});
      }
      if(!vis[e.first][po+1] && ch[ux] && e.first^prv)
    }
  }

  return 0;
}
