#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+3;
int a[N], b[N], x[N], y[N], c[N];
bool vis[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0); cout.tie(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	for(int i=2;i<=n;i++) cin >> c[i];
	for(int i=2;i<=n;i++) cin >> x[i];
	for(int i=2;i<=n;i++) cin >> y[i];
	vector<ll> dp(n+1, 1e18);
	pq.emplace(dp[1]=0, 1);
	while(!pq.empty()){
		auto [d, u] = pq.top();
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=2;i<=n;i++){
			if(x[i]==1 && a[i]<=a[u]) continue;
			if(x[i]==-1 && a[i]>=a[u]) continue;
			if(y[i]==1 && b[i]<=b[u]) continue;
			if(y[i]==-1 && b[i]>=b[u]) continue;
			if(!vis[i] && dp[i]>d+c[i]){
				dp[i]=d+c[i];
				pq.emplace(dp[i], i);
			}
		}
	}
	int q,t; cin >> q;
	while(q--){
		cin >> t;
		if(vis[t]) cout << "-1\n";
		else cout << dp[t] << "\n";
	}

	return 0;
}