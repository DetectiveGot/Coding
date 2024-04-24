#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define tpi tuple<int,int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 3001;
vector<tpi> g;
int pa[N];

inline int fp(int x){
	if(pa[x]==x) return x;
	return pa[x]=fp(pa[x]);
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,u,v,w,r; cin >> n >> m;
	iota(pa, pa+n, 0);
	for(int i=0;i<m;i++){
		cin >> u >> v >> w >> r;
		if(r==1){
			u = fp(u), v = fp(v);
			if(u==v) continue;
			pa[v]=u;
		} else g.emplace_back(w,u,v);
	}
	int p; cin >> p;
	vector<pii> vec(p);
	for(auto &e:vec) cin >> e.second >> e.first;
	sort(vec.begin(), vec.end());
	sort(g.begin(), g.end());
	ll ans=0;
	for(auto &[ww, uu , vv]:g){
		u=fp(uu), v=fp(vv);
		if(u==v) continue;
		pa[v]=u;
		for(auto &e:vec){
			if(e.second>=ww){
				ans+=e.first;
				break;
			}
		}
	}
	cout << ans;

	return 0;
}
