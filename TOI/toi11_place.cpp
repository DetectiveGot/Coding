#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2e5+1;
int pa[N];
vector<tiii> g;

inline int fp(int x){
	if(pa[x]==x) return x;
	return pa[x]=fp(pa[x]);
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,u,v,w; cin >> n >> m;
	iota(pa+1, pa+n+1, 1);
	for(int i=0;i<m;i++){
		cin >> u >> v >> w,--w;
		g.emplace_back(w,u,v);
	}
	sort(g.begin(), g.end(), greater<tiii>());
	ll ans=0;
	for(auto &[w,u,v]:g){
		u=fp(u), v=fp(v);
		if(u==v) continue;
		pa[v]=u;
		ans+=w;
	}
	cout << ans;

	return 0;
}
