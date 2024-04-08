#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

const int mxN = 1e5+2, N = 202;
vector<pii> g[mxN], dist[mxN];
struct DATA{
	int ux, l, r;
	bool operator < (const DATA &dt) const{
		return r-l>dt.r-dt.l;
	}
};
priority_queue<DATA> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,st,ed,u,v,w; cin >> n >> m >> st >> ed;
	while(m--){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	q.push({st, (int)1e9, (int)-1e9});
	while(!q.empty()){
		int ux=q.top().ux, l=q.top().l, r=q.top().r;
		q.pop();
		if(ux==ed){
			cout << r-l;
			return 0;
		}
		for(auto&e:g[ux]){
			bool ok = true;
			int lt=min(e.second, l), rt=max(e.second, r);
			for(auto&s:dist[e.first]){
				if(s.first>=lt && s.second<=rt){
					ok=false;
					break;
				}
			}
			if(ok){
				q.push({e.first, lt, rt});
				dist[e.first].push_back({lt, rt});
			}
		}
	}
	
	return 0;
}
/*
8 9 1 8
1 2 3
1 3 5
3 5 3
2 7 1
3 4 4
4 7 2
4 6 4
6 7 8
7 8 7
Ans: 4
*/
