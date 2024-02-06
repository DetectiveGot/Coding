#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 101, mxM = 2e4+1;
int a[N],dp[N][mxM],n,M;
//can don't eating more than 2 hours

inline int solve(int i, int m){
	if(i>n) return 0;
	if(dp[i][m]!=-1) return dp[i][m];
	if(i==0) dp[i][m]=solve(i+1, m);
	else dp[i][m]=solve(i+1, m*2/3);
	dp[i][m]=max(dp[i][m], solve(i+2, m));
	dp[i][m]=max(dp[i][m], solve(i+3, M));
	dp[i][m]+=min(a[i], m);
	return dp[i][m];
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> n >> M;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=0;i<=n;i++) for(int j=0;j<=M;j++) dp[i][j]=-1;
	cout << solve(0, M);
	
	return 0;
}
