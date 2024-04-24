#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 401;
int a[N];
pii dp[N][N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc,kk,ans=0; cin >> tc >> kk;
	auto add = [](const pii &x, const pii &y){
		return make_pair(x.first+y.first, x.second+1);
	};
	while(tc--){
		int n; cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i], dp[i][i]={1, 1};
		for(int d=1;d<n;d++){
			for(int i=1,j=i+d;i<=n-d;i++,j++){
				dp[i][j]=dp[i][j-1];
				++dp[i][j].first, dp[i][j].second=1;
				for(int k=i;k<j;k++)
					if(a[k]==a[j] && dp[i][k].second<kk) dp[i][j]=min(dp[i][j], add(dp[i][k], dp[k+1][j-1]));
			}
		}
		ans=max(ans, dp[1][n].first);
	}
	cout << ans;

	return 0;
}
