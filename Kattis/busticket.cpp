#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1;
ll a[N], dp[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int s,p,m,n;
	cin >> s >> p >> m >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) {
		dp[i]=dp[i-1]+s;
		int po = lower_bound(a+1, a+n+1, a[i]-m+1)-a;
		dp[i]=min(dp[i], dp[po-1]+p);
	}
	cout << dp[n];

	return 0;
}
