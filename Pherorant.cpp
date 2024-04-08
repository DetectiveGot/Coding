#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 1e5+5, mxMP=332;
vector<int> g[N], vec;
ll dist[N], ser[N], b[N], mp[N];
bool vis[N],ban[N];

int bfs(int u, int &spike){
	if(ban[1] || ban[spike]) return -1;
	queue<int> q;
	for(int i=1;i<=spike;i++) vis[i]=0;
	q.push(u); vis[u]=1;
	while(!q.empty()){
		int ux=q.front();
		q.pop();
		if(ux==spike) return dist[ux];
		for(auto&e:g[ux]){
			if(!vis[e] && !ban[e]){
				vis[e]=1;
				dist[e]=dist[ux]+1;
				q.push(e);
			}
		}
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	freopen("in_all.txt", "r", stdin);
//	freopen("out_all.txt", "w", stdout);
	int n,m,k,l; cin >> n >> m >> k >> l;
	for(int i=1;i<=n;i++){
		int t; cin >> t;
		if(!ser[t]) vec.push_back(t);
		ser[t]++;
	}
	for(auto&e:vec) mp[ser[e]]++;
	for(int i=0;i<l;i++){
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll ans=0;
	for(int i=2;i<=n;i++) cin >> b[i];
	for(int i=1;i<=n;i++){
		ban[b[i]]^=1;
		if(mp[i]) ans+=bfs(1,k)*mp[i]*i*1LL;
	}
	cout << ans;
	
	return 0;
}
