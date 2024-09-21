#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 1e5+1;
int h[N], ans[N];
vector<int> g[N], lis[N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,s,t,u,v; cin >> n >> s >> t;
    for(int i=1;i<=n;i++) cin >> h[i];
    for(int i=1;i<n;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto solve = [&](const int &st) -> void {
        vector<bool> vis(n+1);
        queue<int> qu;
        qu.push(st); vis[st]=1;
        lis[st].push_back(h[st]);
        while(!qu.empty()){
            u = qu.front();
            qu.pop();
            for(auto &e:g[u]){
                if(vis[e]) continue;
                vis[e]=1;
                qu.push(e);
                lis[e]=lis[u];
                int it = lower_bound(lis[e].begin(), lis[e].end(), h[e])-lis[e].begin();
                if(it==lis[e].size()) lis[e].push_back(h[e]);
                else lis[e][it]=h[e];
                ans[e]+=it+1;
            }
            vector<int>().swap(lis[u]);
        }
    };
    solve(t);
    for(int i=1;i<=n;i++) h[i]=-h[i];
    solve(s);
    int q; cin >> q;
    while(q--){
        cin >> u;
        cout << ans[u]-1 << "\n";
    }

    return 0;
}