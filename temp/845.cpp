#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e6+1, K = 61;
int bi[N][K];
vector<int> g[N];
bool vis[N];

inline void dfs(int u, int p){
	vis[u]=1;
	bi[u][0]=p;
	for(int i=1;i<K;i++) bi[u][i]=bi[bi[u][i-1]][i-1];
	for(auto &e:g[u]){
		if(!vis[e]) dfs(e, u);
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	ll m;
	int n,s; cin >> n >> m >> s;
	for(int i=1;i<=n;i++){
		int v; cin >> v;
		v+=i;
		g[i].push_back(i);
	}
	dfs(s, s);
	int node=s;
	for(int i=0;i<K;i++){
		if(m&(1<<i)) node=bi[node][i];
	}
	cout << node;
	
	return 0;
}
