#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+3, mxN = 1e5+1;
ll a[N], b[N];
int dp[101][mxN], n;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<mxN;j++){
			dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			if(j-a[i]>=0) dp[i][j]=max(dp[i][j], dp[i-1][j-a[i]]+1);
			if(j-a[i]-b[i]>=0) dp[i][j]=max(dp[i][j], dp[i-1][j-a[i]-b[i]]+2);
		}
	}
	int q; cin >> q;
	ll x;
	while(q--){
		cin >> x;
		int ans=0;
		for(int i=1;i<=n;i++) ans=max(ans, dp[i][x]);
		cout << ans << "\n";
	}

	return 0;
}
