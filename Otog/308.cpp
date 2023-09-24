#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 102;
ll a[N], dp[N][N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	++n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int d=1;d<n;d++){
		for(int i=1;i<=n-d;i++){
			int j=i+d;
			dp[i][j]=1e9;
			for(int k=i;k<j;k++){
				dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]);
			}
		}
	}
	cout << dp[2][n];
	
	return 0;
}
