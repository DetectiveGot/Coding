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
		for(int j=0;j<=n;j++) dp[i&1][j]=0, qs[j]=0;
		for(int j=0;j<=n;j++){
			(qs[j]+=dp[(i+1)&1][j])%=mod;
			if(j+a[i]+1<=n) (qs[j+a[i]+1]-=dp[(i+1)&1][j])%=mod;
			(qs[max(j-c[i],0)]+=dp[(i+1)&1][j])%=mod;
			(qs[j]-=dp[(i+1)&1][j])%=mod;
		}
		for(int j=0;j<=n;j++){
			if(j) qs[j]+=qs[j-1];
			qs[j]%=mod;
			dp[i&1][j]+=qs[j];
			dp[i&1][j]%=mod;
		}
	}
	ans=(dp[t&1][n]+mod)%mod;
	memset(dp, 0, sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=t;i++){
		for(int j=0;j<=m;j++) dp[i&1][j]=0, qs[j]=0;
		for(int j=0;j<=m;j++){
			(qs[j]+=dp[(i+1)&1][j])%=mod;
			if(j+b[i]+1<=m) (qs[j+b[i]+1]-=dp[(i+1)&1][j])%=mod;
			(qs[max(j-d[i],0)]+=dp[(i+1)&1][j])%=mod;
			(qs[j]-=dp[(i+1)&1][j])%=mod;
		}
		for(int j=0;j<=m;j++){
			if(j) qs[j]+=qs[j-1];
			qs[j]%=mod;
			dp[i&1][j]+=qs[j];
			dp[i&1][j]%=mod;
		}
	}
	ans*=(dp[t&1][m]+mod)%mod;
	ans%=mod;
	cout << ans;
	
	return 0;
}