#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e4+1, P = 1e4+1, mod = 1e9+7;
int dp[P];

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,p,t;
	cin >> n >> m >> p;
	for(int i=1; i<=n; i++) {
		cin >> t;
		dp[t]++;
	}
	for(int i=1; i<=m; i++) {
		cin >> t;
		for(int j=1;j<t;j++){
			int x = t+j>>1;
			if(x==j) continue;
			dp[x]+=dp[j];
			if(dp[x]>=mod) dp[x]-=mod;
		}
		for(int j=p;j>t;--j){
			int x = t+j>>1;
			if(x==j) continue;
			dp[x]+=dp[j];
			if(dp[x]>=mod) dp[x]-=mod;
		}
	}
	for(int i=1; i<=p; i++) cout << dp[i] << "\n";

	return 0;
}
