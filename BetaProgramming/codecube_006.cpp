#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1;
int a[N], dp[N][3];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		if(i&1){
			dp[i][0]=dp[i-1][0]-a[i];
			dp[i][1]=min(dp[i-1][1]+a[i], dp[i-1][0]+a[i]);
			dp[i][2]=min(dp[i-1][2]-a[i], dp[i-1][1]-a[i]);
		} else {
			dp[i][0]=dp[i-1][0]+a[i];
			dp[i][1]=min(dp[i-1][1]-a[i], dp[i-1][0]-a[i]);
			dp[i][2]=min(dp[i-1][2]+a[i], dp[i-1][1]+a[i]);
		}
	}
	int ans=1e9;
	for(int i=0;i<=2;i++) ans=min(ans, dp[n][i]);
	cout << ans;
	
	return 0;
}
