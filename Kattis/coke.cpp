#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 151;
int dp[N][201][51],c;

inline int DP(int i, int n1, int n5, int n10) {
	if(i==c) return dp[i][n5][n10]=0;
	if(dp[i][n5][n10]!=-1) return dp[i][n5][n10];
	int mn = 1e9;
	// 10-1
	if(n10>=1) mn=min(mn, DP(i+1, n1+2, n5, n10-1)+1);
	// 5-1, 1-3
	if(n5>=1 && n1>=3) mn=min(mn, DP(i+1, n1-3, n5-1, n10)+4);
	// 5-2
	if(n5>=2) mn=min(mn, DP(i+1, n1+2, n5-2, n10)+2);
	// 1-8
	if(n1>=8) mn=min(mn, DP(i+1, n1-8, n5, n10)+8);
	// 10 + 3 -> 5
	if(n10>=1 && n1>=3) mn=min(mn, DP(i+1, n1+3, n5+1, n10-1)+4);
	return dp[i][n5][n10]=mn;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc;
	cin >> tc;
	while(tc--) {
		int n1,n5,n10;
		cin >> c >> n1 >> n5 >> n10;
		memset(dp,-1,sizeof dp);
		cout << DP(0, n1, n5, n10) << "\n";
	}

	return 0;
}
