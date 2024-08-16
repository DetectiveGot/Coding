#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
pii par[N];
int sz[N];
bool bi[N];
vector<int> ans;

inline pii fp(int x){
	if(par[x].first^x){
		int y = par[x].second;
		par[x]=fp(par[x].first);
		par[x].second^=y;
	}
	return par[x];
}

inline void merge(int u, int v){
	pii pu=fp(u), pv=fp(v);
	u=pu.first, v=pv.first;
	int x=pu.second, y=pv.second;
	if(u==v){
		if(x==y) bi[u]=false;
	} else {
		if(sz[u]<sz[v]) swap(u,v);
		par[v]={u, x^y^1};
		bi[u]&=bi[v];
		if(sz[u]==sz[v]) ++sz[u];
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,q; cin >> n >> m >> q;
	for(int i=1;i<=n;i++) par[i]={i, 0}, bi[i]=true;
	for(int i=0;i<m;i++){
		int u,v; cin >> u >> v;
		merge(u,v);
	}
	while(q--){
		int cmd,a,b,c,p,v; cin >> cmd;
		if(cmd==1){
			cin >> a >> b >> c >> p >> v;
			pii pa=fp(a), pb=fp(b), pc=fp(c), pp=fp(p);
			a=pa.first, b=pb.first, c=pc.first, p=pp.first;
			if(a==b && b==c && c==p){
				if(!bi[p] || (pa.second==pb.second && pb.second==pc.second)) ans.push_back(v);
				else ans.push_back(0);
			} else ans.push_back(0);
		} else {
			cin >> p >> v;
			merge(p,v);
		}
	}
	sort(ans.begin(), ans.end(), greater<int>());
	ll s=0;
	for(auto &e:ans){
		s+=e;
		cout << s << "\n";
	}
	
	return 0;
}