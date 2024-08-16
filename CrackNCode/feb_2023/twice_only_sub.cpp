#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e3+1;
ll dp[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	dp[0][0]=1;
	ll ans=0;
	for(int k=1; k<=n/3; k++) {
		for(int i=3; i<=n; i++) {
			dp[k][i]=dp[k-1][i-3]*((i-1)*(i-2))/2%m+dp[k][i-1]*(i-1)%m;
		}
		ans+=dp[k][n];
		ans%=m;
	}
	cout << ans;

	return 0;
}