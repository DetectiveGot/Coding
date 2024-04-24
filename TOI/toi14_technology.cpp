#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
vector<int> g[N], pos[N];
int vis[N],t;

inline bool dfs(int u){
	vis[u]=1;
	--t;
	bool ok=true;
	for(auto &e:g[u]){
		if(!vis[e]) ok&=dfs(e);
		else if(vis[e]==1) ok=false;
	}
	vis[u]=2;
	return ok;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,k,p,lvl,u,v; cin>> n >> k >> t;
	for(int i=1;i<=n;i++){
		cin >> lvl >> p;
		pos[lvl].push_back(i);
		for(int j=0;j<p;j++){
			cin >> u;
			g[i].push_back(u);
		}
	}
	int ans=-1;
	bool ok=true;
	for(int i=1;i<=k;i++){
		ok=true;
		for(auto &e:pos[i]) if(!vis[e]) ok&=dfs(e);
		ok&=t>=0;
		if(ok) ans=i;
		else break;
	}
	cout << ans;

	return 0;
}
