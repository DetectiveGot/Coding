#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
vector<pii> g[N];
int deg[N];
ll dp[N];
bool vis[N];
priority_queue<pii, vector<pii>, greater<pii>> pq; //risk, now

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,u,v,w;
	cin >> n;
	for(int i=1; i<=n; i++) cin >> dp[i];
	for(int i=1; i<n; i++) {
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		deg[u]++, deg[v]++;
	}
	for(int i=1; i<=n; i++) if(deg[i]==1) pq.push({0, i});
	ll ans=0;
	while(pq.size()) {
		ll risk = pq.top().first;
		int ux = pq.top().second;
		pq.pop();
		deg[ux]--;
		if(deg[ux]>1) {
			ans+=risk;
			continue;
		}
		if(vis[ux]) continue;
		vis[ux]=1;
		for(auto &e:g[ux]) {
			if(vis[e.first]) continue;
			dp[e.first]+=dp[ux];
			pq.push({risk+dp[ux]*e.second, e.first});
		}
	}

	cout << ans;

	return 0;
}