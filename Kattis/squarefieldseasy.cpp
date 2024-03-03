#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 16;
int dp[N][1<<N|1];
pii a[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc,cs=0;
	cin >> tc;
	while(tc--) {
		int n,k;
		cin >> n >> k;
		for(int i=0; i<n; i++) cin >> a[i].first >> a[i].second;
		for(int mask=1; mask<1<<n; mask++) {
			int mnx=1e9,mny=1e9,mxx=-1e9,mxy=-1e9;
			for(int j=0; j<n; j++) if(mask&1<<j) {
					mnx=min(mnx, a[j].first);
					mny=min(mny, a[j].second);
					mxx=max(mxx, a[j].first);
					mxy=max(mxy, a[j].second);
				}
			dp[1][mask]=max({abs(mxx-mnx), abs(mxy-mny),1});
		}
		for(int i=2; i<=k; i++) {
			for(int mask=1; mask<1<<n; mask++) {
				dp[i][mask]=dp[i-1][mask];
				for(int m=(mask-1)&mask; m>0; m=(m-1)&mask) {
					int m2 = mask^m;
					dp[i][mask]=min(dp[i][mask], max(dp[i-1][m], dp[1][m2]));
				}
			}
		}
		cout << "Case " << "#" << ++cs << ": " << dp[k][(1<<n)-1] << "\n";
	}

	return 0;
}
