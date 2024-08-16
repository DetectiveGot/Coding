#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
int dist[N], a[N];
bool vis[N];
vector<pii> g[N];
vector<int> pos;
unordered_map<int,int> mp[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,qq;
	cin >> n >> qq;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		if(a[i]==1) pos.push_back(i);
	}
	int u,v,w;
	for(int i=1; i<n; i++) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for(auto &pp:pos) {
		dist[pp]=0;
		queue<pii> q;
		memset(vis, 0, sizeof(vis));
		q.push({pp, 0});
		vis[pp]=1;
		while(!q.empty()) {
			auto [ux, d] = q.front();
			q.pop();
			dist[ux]=max(dist[ux], d);
			for(auto &e:g[ux]) {
				if(vis[e.first] || a[e.first]) continue;
				if(!mp[ux].count(e.first) || (mp[ux][e.first]<d+e.second)) {
					mp[ux][e.first]=d+e.second;
					vis[e.first]=1;
					q.push({e.first, d+e.second});
				}
			}
		}
	}
	int t;
	while(qq--) {
		cin >> t;
		cout << dist[t] << "\n";
	}

	return 0;
}