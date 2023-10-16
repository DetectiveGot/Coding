#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 5001;
ll a[N], dp[N][N], qs[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	ll ans=0;
	for(int i=1;i<=n;i++) cin >> a[i], dp[1][i]=a[i], qs[i]=qs[i-1]+a[i], ans=max(ans, a[i]);
	for(int i=2;i<=n;i++){
		for(int j=i-1;j<=n;j++){ 
			int pz=i-1;
			for(int k=i;k<=j-pz;k++) dp[i][k]=max(dp[i][k], dp[i-1][j]+qs[k]-qs[k-i]);
			for(int k=j+i;k<=n;k++) dp[i][k]=max(dp[i][k], dp[i-1][j]+qs[k]-qs[k-i]);
			for(int k=j;k<=j+i-1;k++) dp[i][k]=max(dp[i][k], dp[i-1][j]+(qs[k]-qs[k-i])/2);
		}
		for(int j=i;j<=n;j++) ans=max(ans, dp[i][j]);
	}
	cout << ans;
	
	return 0;
}
