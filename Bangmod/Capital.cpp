#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 10001;
queue<int> q;
int dist[N];
vector<pii> g[N];

inline void dfs(int u, int p){
	for(auto &e:g[u]){
		if(e.first==p) continue;
		dist[e.first]=dist[u]+e.second;
		dfs(e.first, u);
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,u,v,w; cin >> n;
	for(int i=1;i<n;i++){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dfs(1, -1);
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans, dist[i]);
	cout << ans;
	
	return 0;
}
/*
11
1 2 1427
1 3 741
1 4 1763
1 5 2491
1 6 1849
2 7 1219
3 8 1100
4 9 1071
3 10 1587
2 11 1418

2845
*/
