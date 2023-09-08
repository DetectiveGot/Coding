#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
vector<int> g[N];
vector<pii> tp[3];
int pa[N], vis[N];

int fp(int x){
	if(pa[x]==x) return x;
	return pa[x]=fp(pa[x]);
}

void dfs(int u){
	vis[u]=1;
	for(auto &e:g[u]){
		if(!vis[e]) dfs(e);
		vis[u]=max(vis[u], vis[e]+1);
//		deb(u); deb(e) << endl;
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,u,v,pu,pv; cin >> n >> m;
	char c;
	iota(pa+1, pa+n+1, 1);
	for(int i=0;i<m;i++){
		cin >> u >> v >> c;
		if(c=='=') tp[2].push_back({u,v});
		else if(c=='>') tp[1].push_back({u,v});
		else tp[0].push_back({v,u});
	}
	for(auto &e:tp[2]){
		pu=fp(e.first), pv=fp(e.second);
		if(pu==pv) continue;
		pa[pv]=pu;
	}
	for(int i=0;i<2;i++){
		for(auto &e:tp[i]){
			pu=fp(e.first), pv=fp(e.second);
			g[pu].push_back(pv);
		}
	}
	for(int i=1;i<=n;i++){
		pu = fp(i);
		if(!vis[pu]) dfs(pu);
		cout << vis[pu] << "\n";
	}
	
	return 0;
}
/*
5 4
1 2 >
2 3 <
4 3 =
5 4 >
*/
