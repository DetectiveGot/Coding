#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e6+1, T = 11, mod = 1e9+7;
int a[N], b[N], c[N], d[N];
ll dp[2][N], qs[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,t; cin >> n >> m >> t;
	ll ans=0;
	dp[0][0]=1;
	for(int i=1;i<=t;i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
	for(int i=1;i<=t;i++){
		int now = i&1, pre = now^1;
		dp[pre][0]=0;
		for(int j=0;j<=n;j++){
			dp[now][j]=0;
			dp[pre][j]+=dp[pre][j-1];
		}
		dp[pre][0]=0;
		for(int j=1;j<=n;j++){
			(dp[pre][j]+=dp[pre][j])%=mod;
			if(j+a[i]+1<=n) (dp[pre][j+a[i]+1]-=dp[pre][j])%=mod;
			(dp[pre][max(j-c[i],0)]+=dp[pre][j])%=mod;
			(dp[pre][j]-=dp[pre][j])%=mod;
		}
		dp[pre][0]=0;
		for(int j=1;j<=n;j++){
			if(j) dp[pre][j]+=dp[pre][j-1];
			dp[pre][j]%=mod;
			dp[now][j]%=mod;
		}
	}
	ans=(dp[t&1][n]+mod)%mod;
	memset(dp, 0, sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=t;i++){
		for(int j=0;j<=m;j++) dp[now][j]=0, qs[j]=0;
		for(int j=0;j<=m;j++){
			(dp[pre][j]+=dp[(i+1)&1][j])%=mod;
			if(j+b[i]+1<=m) (dp[pre][j+b[i]+1]-=dp[pre][j])%=mod;
			(dp[pre][max(j-d[i],0)]+=dp[pre][j])%=mod;
			(dp[now][j]-=dp[pre][j])%=mod;
		}
		dp[pre][0]=0;
		for(int j=0;j<=m;j++){
			if(j) dp[pre][j]+=dp[pre][j-1];
			dp[now][j]%=mod;
		}
	}
	ans*=(dp[t&1][m]+mod)%mod;
	ans%=mod;
	cout << ans;
	
	return 0;
}
