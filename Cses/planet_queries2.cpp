#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pii pair<int,int>
#define tpi tuple<int,int,int>
#define vi vector<int>
#define vvi vector<vi>
#define sz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "]"

using namespace std;
using namespace __gnu_pbds;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mxN = 2e5+1;
int adj[mxN], deg[mxN], dist[mxN], cdist[mxN], pa[mxN], cyc[mxN], sz[mxN], id = 0, idc = 0;
int tin[mxN], tout[mxN];
bool vis[mxN];
vector<int> g[mxN];

void dfs(int u, int p){
    tin[u]=++idc;
    for(auto &e:g[u]){
        if(deg[e]) continue;
        dist[e]=dist[u]+1;
        cyc[e]=cyc[u];
        pa[e]=pa[u];
        dfs(e, u);
    }
    tout[u]=idc;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> adj[i];
        g[adj[i]].emplace_back(i);
        deg[adj[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(deg[i] || vis[i]) continue;
        int u = i;
        while(true){
            vis[u]=true;
            int v = adj[u];
            --deg[v];
            if(deg[v]==0) u = v;
            else break;
        }
    }
    fill(vis, vis+n+1, false);
    for(int i=1;i<=n;i++){
        if(!deg[i] || vis[i]) continue;
        ++id;
        int u = i;
        while(!vis[u]){
            int v = adj[u];
            vis[u]=true;
            cyc[u]=id;
            sz[id]++;
            cdist[v]=cdist[u]+1;
            u = v;
        }
    }
    iota(pa+1, pa+n+1, 1);
    for(int i=1;i<=n;i++){
        if(!deg[i]) continue;
        dfs(i, i);
    }
    // for(int i=1;i<=n;i++) cout << cdist[i] << " "; cout << "\n";
    // deb(dist[2]), deb(pa[2]), deb(cdist[pa[2]]), deb(cdist[9]) << "\n";
    while(q--){
        int u, v; cin >> u >> v;
        int ans = -1;
        if(cyc[u]!=cyc[v] || (deg[u] && !deg[v])){
            cout << "-1\n";
            continue;
        }
        // if(deg[v]) swap(u, v);
        if(deg[u] && deg[v]) ans = (cdist[v]-cdist[u]+sz[cyc[u]])%sz[cyc[u]];
        else if(deg[u]) ans=dist[v]+(cdist[u]-cdist[pa[v]]+sz[cyc[u]])%sz[cyc[u]];
        else if(deg[v]) ans=dist[u]+(cdist[v]-cdist[pa[u]]+sz[cyc[v]])%sz[cyc[v]];
        else if(tin[v]<=tin[u] && tout[v]>=tout[u]) ans = abs(dist[v]-dist[u]);
        cout << ans << "\n";
    }

    return 0;
}
