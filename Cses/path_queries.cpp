#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5+2;
int val[N];
vector<int> g[N];

bool dfs(int u, int s, int x){
	bool chk=0;
	if(u==s){
		val[u]+=x;
		return 1;
	}
	for(auto&e:g[u]){
		chk|=dfs(e, s, x);
	}
	if(chk) val[u]+=x;
	return chk;
}

void dfs2(int u){
	for(auto&e:g[u]){
		val[e]+=val[u];
		dfs2(e);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,q,u,v; cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> val[i];
	for(int i=0;i<n-1;i++){
		cin >> u >> v;
		g[u].push_back(v);
	}
	dfs2(1);
	while(q--){
		int cmd,s,x; cin >> cmd;
		if(cmd==1){
			cin >> s >> x;
			dfs(1, s, x-val[s]);
		} else {
			cin >> s;
			cout << val[s] << "\n";
		}
	}
	
	return 0;
}
