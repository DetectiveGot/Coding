#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,ll>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 5e4+1;
unordered_map<string, int> mp;
vector<pii> dist[N], g[N];
ll id[N];
struct DATA{
	int ux;
	ll gl,dx;
	bool operator < (const DATA &dt) const{
		if(dx==dt.dx) return gl>dt.gl;
		return dx>dt.dx;
	}
};
priority_queue<DATA> pq;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string a,b,p,u,v;
	ll fl,t,w;
	int n,m,uu,vv,st,ed; cin >> n >> m >> a >> b >> fl;
	for(int i=1;i<=n;i++){
		cin >> p >> t;
		mp[p]=i;
		id[i]=t;
	}
	for(int i=0;i<m;i++){
		cin >> u >> v >> w;
		uu=mp[u], vv=mp[v];
		g[uu].push_back({vv,w});
		g[vv].push_back({uu,w});
	}
	st=mp[a], ed=mp[b];
	pq.push({st, 0, id[st]});
	while(!pq.empty()){
		int ux=pq.top().ux;
		ll gl=pq.top().gl, dx=pq.top().dx;
		pq.pop();
		for(auto &e:g[ux]){
			if(e.second+gl>fl) continue;
			bool ok = true;
			ll mx=max(dx, id[e.first]), gg=e.second+gl;
			for(auto &x:dist[e.first]){
				if(mx>=x.first && gg>=x.second){
					ok=false;
					break;
				}
			}
			if(ok){
				dist[e.first].push_back({mx, gg});
				pq.push({e.first, gg, mx});
			}
		}
	}
	ll ans1=1e18, ans2=1e18;
	for(auto &e:dist[ed]){
		if(ans1>e.first) ans1=e.first, ans2=e.second;
		else if(ans1==e.first) ans2=min(ans2, e.second);
	}
	cout << ans1 << " " << ans2;
	
	return 0;
}

