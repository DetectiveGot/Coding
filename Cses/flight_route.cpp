#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

const int N = 1e5+2;
struct DATA{
	int u;
	ll dx;
	bool operator < (const DATA &dt) const{
		return dx>dt.dx;
	}
};
vector<pii> g[N];
priority_queue<DATA> pq;
vector<ll> ans[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k,u,v,w; cin >> n >> m >> k;
	while(m--){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
	}
	pq.push({1,0});
	while(!pq.empty()){
		int ux=pq.top().u;
		ll dx=pq.top().dx;
		pq.pop();
//		cout << ux << " " << dx << endl;
		if(ans[ux].size()>=k) continue;
		ans[ux].push_back(dx);
		for(auto&e:g[ux]){
			pq.push({e.first, e.second*1LL+dx});
		}
	}
	for(auto&e:ans[n]) cout << e << " ";
	
	return 0;
}
