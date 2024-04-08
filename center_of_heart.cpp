#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 3e5+2;
int pa[N];
vector<pii> edges;

int fp(int &x){
	if(pa[x]==x) return x;
	return pa[x]=fp(pa[x]);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,t,d,u,v; cin >> n >> m >> t >> d;
	for(int i=1;i<=n;i++) pa[i]=i;
	for(int i=0;i<t;i++){
		cin >> u >> v;
		edges.push_back({u,v});
	}
	int comp=n;
	while(m--){
		cin >> u >> v;
		int pu=fp(u), pv=fp(v);
		if(pu==pv) continue;
		pa[pv]=pu;
		comp--;
	}
	for(int i=0;i<t;i++){
		u=fp(edges[i].first), v=fp(edges[i].second);
		if(u==v) continue;
		pa[v]=u;
		if(--comp<=d){
			cout << i+1;
			return 0;
		}
	}
	cout << -1;
	
	return 0;
}
