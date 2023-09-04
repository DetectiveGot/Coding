#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

const int N = 1e5+2;
struct DATA{
	int ux,use;
	ll dx;
	bool operator < (const DATA &dt) const{
		return dx>dt.dx;
	}
};
vector<pii> g[N];
ll dp[N][2];
bool vis[N][2];
priority_queue<DATA> pq;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,u,v,w; cin >> n >> m;
	for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=1e18;
	while(m--){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
	}
	dp[1][0]=dp[1][1]=0;
	pq.push({1,0,dp[1][0]});
	while(!pq.empty()){
		int ux=pq.top().ux, use=pq.top().use;
		ll dx=pq.top().dx;
		pq.pop();
		if(vis[ux][use]) continue;
		vis[ux][use]=1;
		for(auto&e:g[ux]){
			if(!vis[e.first][use] && dp[e.first][use]>dx+e.second){
				dp[e.first][use]=dx+e.second;
				pq.push({e.first, use, dp[e.first][use]});
			}
			if(!vis[e.first][1] && !use && dp[e.first][1]>dx+e.second/2){
				dp[e.first][1]=dx+e.second/2;
				pq.push({e.first, 1, dp[e.first][1]});
			}
		}
	}
	cout << min(dp[n][0], dp[n][1]);
	
	return 0;
}
