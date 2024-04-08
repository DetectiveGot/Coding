#include<bits/stdc++.h>

using namespace std;

const int N = 502;
int a[N], dp[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i], dp[i][i]=a[i];
	for(int d=2;d<n;d++){
		for(int i=1;i<=n-d;i++){
			int j=i+d;
			dp[i][j]=a[i]+a[j]+max(dp[i][j-1], dp[i+1][j]);
			for(int k=i+1;k<j;k++){
				dp[i][j]=max(dp[i][j], dp[i][k]+dp[k][j]+a[i]+a[j]);
			}
		}
	}
	cout << dp[1][n];
	
	return 0;
}
