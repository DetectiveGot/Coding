#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
ll a[N], fb[N];
unordered_map<ll, int> mp;
vector<int> g[N], ts;
int dp[N];
bool vis[N];

inline void dfs(int u){
	vis[u]=1;
	dp[u]=max(dp[u], 1);
	for(auto &e:g[u]){
		if(vis[e]) continue;
		dfs(e);
	}
	ts.push_back(u);
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,u,v; cin >> n >> m;
	fb[1]=1;
	for(int i=2;i<=88;i++){
		fb[i]=fb[i-1]+fb[i-2];
		mp[fb[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(mp.find(a[i])!=mp.end()) dp[i]=1;
	}
	for(int i=0;i<m;i++){
		cin >> u >> v;
		if(!dp[u] || !dp[v]) continue;
		if(a[u]>a[v]) swap(u,v);
		if(mp[a[u]]+1==mp[a[v]]) g[u].push_back(v);
		else if(a[u]==1 && a[v]==1) dp[u]=dp[v]=2;
	}
	for(int i=1;i<=n;i++){
		if(vis[i] || !dp[i]) continue;
		dfs(i);
	}
	reverse(ts.begin(), ts.end());
	int ans=0;
	for(auto &e:ts){
		ans=max(ans, dp[e]);
		for(auto &x:g[e]) dp[x]=max(dp[x], dp[e]+1);
	}
	cout << ans;
	
	return 0;
}
