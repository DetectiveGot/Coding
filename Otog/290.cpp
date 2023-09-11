#include<bits/stdc++.h>

using namespace std;

const int N = 251;
int a[N][N], dp[N][N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			dp[i][j]=max(dp[i-1][j], dp[i][j-1])+a[i][j];
		}
	}
	cout << dp[n][m];
	
	return 0;
}
