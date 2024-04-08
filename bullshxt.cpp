#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+2, K = 102;
int a[N], dp[N][K];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) {
		dp[i][1]=min(dp[i-1][k], dp[i-1][2]);
		if(a[i]^1) dp[i][1]++;
		dp[i][k]=min(dp[i-1][1], dp[i-1][k-1]);
		if(a[i]^k) dp[i][k]++;
		for(int j=2; j<k; j++) {
			dp[i][j]=min(dp[i-1][j+1], dp[i-1][j-1]);
			if(a[i]^j) dp[i][j]++;
		}
	}
	int mn=1e9;
	for(int i=1; i<=k; i++) mn=min(mn, dp[n][i]);
	cout << mn;

	return 0;
}

/*
5 10
8 9 4 3 2

    a  [8   9   4   3   2]
  i 0   1   2   3   4   5
j
1   0   1   2   3   2   4
2   0   1   2   3   4   2
3   0   1   2   3   2
4   0   1   2   2   4
5   0   1   2   3   3
6   0   1   2   3   4
7   0   1   2   3   2
8   0   0   2   1   4
9   0   1   0   3   2
10  0   1   2   1   4

*/


