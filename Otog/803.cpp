#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 201, R = 15001, mod = 10000009;
ll dp[2][N][R];
char a[2][N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,r; cin >> n >> m >> r;
	dp[1][1][r]=1;
	for(int i=1;i<=n;i++){
		int nw=i&1, pv=nw^1;
		for(int j=1;j<=m;j++){
			cin >> a[nw][j];
			if(a[nw][j]=='#') continue;
			for(int k=0;k<=r;k++){
				if(a[nw][j]=='X'){
					if(k<r){
						dp[nw][j][k]+=dp[pv][j][k+1];
						dp[nw][j][k]%=mod;
						dp[nw][j][k]+=dp[nw][j-1][k+1];
						dp[nw][j][k]%=mod;
					}
				} else {
					dp[nw][j][k]+=dp[pv][j][k];
					dp[nw][j][k]%=mod;
					dp[nw][j][k]+=dp[nw][j-1][k];
					dp[nw][j][k]%=mod;
				}
			}
		}
		for(int j=1;j<=m;j++){
			for(int k=0;k<=r;k++){
				dp[pv][j][k]=0;
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=r;i++){
		ans+=dp[n&1][m][i];
		ans%=mod;
	}
	cout << ans;
	
	return 0;
}
