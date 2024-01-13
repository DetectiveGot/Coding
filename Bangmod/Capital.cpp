#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 10001;
int dist[N];
priority_queue<pii> pq;
bool vis[N];
vector<pii> g[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,u,v,w; cin >> n;
	for(int i=1;i<n;i++){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	memset(dist, -0x3f, sizeof(dist));
	dist[1]=0;
	pq.push({dist[1]=0, 1});
	while(!pq.empty()){
		int ux=pq.top().second, dx=pq.top().first;
		pq.pop();
		if(vis[ux]) continue;
		vis[ux]=1;
		for(auto &e:g[u]){
			if(!vis[e.first] && dist[e.first]<dx+e.second){
				dist[e.first]=dx+e.second;
				deb(ux), deb(e.first) << endl;
				pq.push({dist[e.first], e.first});
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans, dist[i]);
		deb(i), deb(dist[i]) << endl;
	}
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
