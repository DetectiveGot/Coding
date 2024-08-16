#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 5e4+1;
unordered_map<int,ll> dist[N];
unordered_set<int> vis[N];
vector<pii> g[N];
int cost[N], a[N];
struct DATA {
	ll d,u,i;
	bool operator < (const DATA &dt) const {
		return d>dt.d;
	}
};
priority_queue<DATA> pq;

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	ll k,x,t;
	for(int i=0; i<m; i++) {
		cin >> k >> cost[i];
		for(int j=0; j<k; j++) cin >> a[j];
		for(int j=1; j<k; j++) {
			g[a[j]].push_back({a[j-1], i});
			g[a[j-1]].push_back({a[j], i});
		}
	}
	pq.push({dist[0][N-1]=0, 0, N-1});
	while(!pq.empty()) {
		ll u=pq.top().u, d = pq.top().d, i = pq.top().i;
		pq.pop();
		if(vis[u].count(i)) continue;
		vis[u].insert(i);
		if(u==n-1) {
			cout << d;
			return 0;
		}
		for(auto &e:g[u]) {
			int add = cost[e.second];
			if(e.second==i) add=0;
			if(!vis[e.first].count(e.second) && (!dist[e.first].count(e.second) || dist[e.first][e.second]>d+add)) {
				dist[e.first][e.second]=d+add;
				pq.push({dist[e.first][e.second], e.first, e.second});
			}
		}
	}
	cout << -1;

	return 0;
}