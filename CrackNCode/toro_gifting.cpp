#include<bits/stdc++.h>

using namespace std;

const int N = 502;
int a[N][N], dp[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			dp[i][j]=a[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];		
		}
	}
	int ans=INT_MIN;
	for(int l=0;l<m;l++){
		for(int r=l+1;r<=m;r++){
			int mx=-1e9, mn=1e9;
			for(int i=0;i<=n;i++){
				mx=max(mx, dp[i][r]-dp[i][l]-mn);
				mn=min(mn, dp[i][r]-dp[i][l]);
			}
			ans=max(mx, ans);
		}
	}
	cout << ans;
	
	return 0;
}
