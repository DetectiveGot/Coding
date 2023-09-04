#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 305, mod=998244353,MxN=2e5+5, oft=1e5;
int a[N], dp[N][MxN];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	dp[2][a[2]+oft]=1;
	for(int i=2;i<=n;i++){
		for(int j=-i*300;j<=i*300;j++){
//			cout << i << " " << j << "\n";
			(dp[i+1][a[i+1]+j+oft]+=dp[i][j+oft])%=mod;
			if(j) (dp[i+1][a[i+1]-j+oft]+=dp[i][j+oft])%=mod;
		}
	}
	int cnt=0;
	for(int i=-n*300;i<=n*300;i++) (cnt+=dp[n][i+oft])%=mod;
	cout << cnt;
	
	return 0;
}
