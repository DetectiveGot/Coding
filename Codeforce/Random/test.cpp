#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+2;
vector<int> g[N];
int cnt[N];

void dfs(int u, int p){
	cnt[u]=1;
	for(auto&e:g[u]){
		if(e==p) continue;
		dfs(e, u);
		cnt[u]+=cnt[e];
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i=2;i<=n;i++){
		int v; cin >> v;
		g[v].push_back(i);
	}
	dfs(1, -1);
	for(int i=1;i<=n;i++) cout << cnt[i]-1 << " ";
	
	return 0;
}
