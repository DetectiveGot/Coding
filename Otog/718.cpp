#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+1, G = 101;
int dp[N][G];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,g,t,ans=0; cin >> n >> g;
	for(int i=1;i<=n;i++){
		cin >> t;
		for(int j=0;j<=g;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=1) dp[i][j]=max(dp[i][j], dp[i-1][j-1]+t);
			dp[i][j]=max(dp[i][j], dp[max(i-2,0)][j]+t);
		}
	}
	for(int i=0;i<=g;i++) ans=max(ans, dp[n][i]);
	cout << ans;
	
	return 0;
}
