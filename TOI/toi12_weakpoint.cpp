#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 5e5+1;
vector<int> g[N];
int dp[N], dp2[N], vis[N], pa[N],ans1,s,mx;
bool cyc[N];

inline void dfs(int u, int p) {
	vis[u]=1;
	for(auto &e:g[u]) {
		if(e==p || vis[e]==2) continue;
		if(vis[e]==1) {
			int v = u;
			while(v!=e) {
				cyc[v]=1;
				v=pa[v];
			}
			cyc[v]=1;
			continue;
		}
		pa[e]=u;
		dfs(e, u);
	}
	vis[u]=2;
}

inline void dfs2(int u, int p) {
	vis[u]=1;
	dp[u]=dp2[u]=1;
	for(auto &e:g[u]) {
		if(e==p) continue;
		if(vis[e]) continue;
		dfs2(e, u);
		if(!cyc[e]) dp[u]+=dp[e];
		dp2[u]+=dp2[e];
		if(mx<dp[u]) {
				mx=dp[u];
				ans1=u;
			} else if(mx==dp[u]) ans1=min(ans1, u);
		} else {
			if(mx<dp2[u]){
				mx=dp2[u];
				ans1=u;
			} else if(mx==dp2[u]) ans1=min(ans1, u);
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,u,v;
	cin >> n >> s;
	for(int i=0; i<n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(s, -1);
	memset(vis, 0, sizeof(vis));
	dfs2(s, -1);
//	for(int i=1;i<=n;i++) deb(i), deb(cyc[i]), deb(dp[i]), deb(dp2[i]) << "\n";
	cout << ans1 << "\n" << mx-1;

	return 0;
}
/*
8 1
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 3
*/
