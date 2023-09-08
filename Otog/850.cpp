#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> g[1000];
int p[1000];
int dist[1000][100];
bool vis[1000][100];
int n, m, u, v, w, st, ed, c, i;

struct DATA {
    int ux, fl, dx;
    bool operator<(const DATA &dt) const {
        return dx > dt.dx;
    }
};

inline void dij() {
    priority_queue<DATA> pq;
    cin >> c >> st >> ed;
    for(int i=0;i<n;i++)
    	for(int j=0;j<=c;j++)
    		dist[i][j]=1e9, vis[i][j]=0;
    dist[st][0]=0;
    pq.push({st, 0, dist[st][0]});
    while (!pq.empty()) {
        int ux = pq.top().ux, fl = pq.top().fl, dx = pq.top().dx;
        pq.pop();
        if (ux == ed) {
            cout << dist[ux][fl] << "\n";
            return;
        }
        if (vis[ux][fl]) continue;
        vis[ux][fl] = true;
        for (i = fl; i <= c; i++) dist[ux][i] = min(dist[ux][i], dx + (i - fl) * p[ux]);
        for (auto &e : g[ux]) {
        	if(fl>=e.second){
        		if (!vis[e.first][fl - e.second] && dist[e.first][fl - e.second] > dist[ux][fl]) {
	                dist[e.first][fl - e.second] = dist[ux][fl];
	                pq.push({e.first, fl - e.second, dist[e.first][fl - e.second]});
	            }
	            if(fl+1<=c && !vis[ux][fl+1]) pq.push({ux, fl+1, dist[ux][fl+1]});
			} else {
				if(fl+1<=c && !vis[ux][fl+1]) pq.push({ux, fl+1, dist[ux][fl+1]});
			}
        }
    }
    cout << "impossible\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    int q;
    cin >> q;
    while (q--) {
        dij();
    }

    return 0;
}


