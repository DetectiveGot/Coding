#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e4+1;
int dist[N];
bool vis[N];
vector<pii> g[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,a,k,u,v,d;
	while(cin >> n >> m >> a >> k) {
		if((n||m||a||k)==0) break;
		for(int i=1;i<=n;i++) vis[i]=0,dist[i]=1e9,g[i].clear();
		for(int i=0; i<m; i++) {
			cin >> u >> v >> d;
			g[u].push_back({v,d});
			g[v].push_back({u,d});
		}
		int cnt=0,x;
		for(int tc=1; tc<=a; tc++) {
			cin >> x;
			priority_queue<pii, vector<pii>, greater<pii>> pq;
			pq.push({dist[x]=0, x});
			while(!pq.empty()) {
				int ux=pq.top().second, dx=pq.top().first;
				pq.pop();
				if(!vis[ux]) ++cnt;
				vis[ux]=1;
				for(auto &e:g[ux]) {
					if(dx+e.second>=k) continue;
					if(dist[e.first]>dx+e.second){
						dist[e.first]=dx+e.second;
						pq.push({dist[e.first], e.first});
					}
				}
			}
			cout << n-cnt << "\n";
		}
		cout << "\n";
	}

	return 0;
}
/*
7 6 3 3
1 2 1
1 3 1
2 5 1
3 6 1
1 4 1
4 7 2
2
1
4
1 0 1 1
1
0 0 0 0
*/
