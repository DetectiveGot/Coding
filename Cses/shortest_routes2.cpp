#include<bits/stdc++.h>
#define ll long long
#define INF LLONG_MAX

using namespace std;

const int N = 502;
ll dp[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k; cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i^j) dp[i][j]=INF;
	int u,v;
	ll w;
	while(m--){
		cin >> u >> v >> w;
		dp[u][v]=min(dp[u][v], w);
		dp[v][u]=min(dp[v][u], w);
	}
	for(int r=1;r<=n;r++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dp[i][r]==INF || dp[r][j]==INF) continue;
				dp[i][j]=min(dp[i][j], dp[i][r]+dp[r][j]);
			}
		}
	}
	while(k--){
		cin >> u >> v;
		if(dp[u][v]==INF) cout << -1 << "\n";
		else cout << dp[u][v] << "\n";
	}
	
	return 0;
}
