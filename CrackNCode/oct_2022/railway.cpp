#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
#define tpi tuple<ll,ll,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
vector<pii> g[N];
ll a[N], dp[N];
int deg[N];
bool vis[N];
priority_queue<pii, vector<pii>, greater<pii>> pq; //risk, people, now

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
	for(int i=1; i<=n; i++) if(deg[i]==1) pq.push({dp[i]*g[i][0].second, i});
	ll ans=0;
	while(pq.size()>2) {
		auto [risk, ux] = pq.top();
		pq.pop();
		deg[ux]--;
		if(vis[ux]) continue;
		vis[ux]=1;
		for(auto &e:g[ux]) {
			if(vis[e.first]) continue;
			dp[e.first]+=dp[ux];
			--deg[e.first];
			if(deg[e.first]==1) {
				for(auto &x:g[e.first]) {
					if(vis[x.first]) continue;
					pq.push({risk+dp[e.first]*x.second, e.first});
					break;
				}
			} else {
				ans+=risk;
			}

		}
	}

	cout << ans;

	return 0;
}