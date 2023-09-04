#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

const int N = 1e5+2;
int a[N];
vector<pii> g[N];
bool vis[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,u,v,w; cin >> n >> m;
	while(m--){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	ll s=0;
	int cnt=0;
	pq.push({0, 1});
	while(!pq.empty()){
		int ux=pq.top().second, dx=pq.top().first;
		pq.pop();
		if(vis[ux]) continue;
		vis[ux]=1;
		s+=dx;
		cnt++;
		for(auto&e:g[ux]){
			if(!vis[e.first]){
				pq.push({e.second, e.first});
			}
		}
	}
	if(cnt==n) cout << s;
	else cout << "IMPOSSIBLE";
	
	return 0;
}
