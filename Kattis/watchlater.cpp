#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 401, K = 21;
ll dp[N][N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,k; cin >> n >> k;
	string s; cin >> s;
	for(int i=1;i<=n;i++) dp[i][i]=1;
	for(int d=1;d<n;d++){
		for(int i=1;i<=n-d;i++){
			int j=i+d;
			dp[i][j]=1e9;
			if(s[i-1]==s[j-1]) dp[i][j]=dp[i+1][j-1]+1;
			else dp[i][j]=min(dp[i+1][j], dp[i][j-1])+1;
			for(int k=i;k<j;k++){
				dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]);
			}
		}
	}
	cout << dp[1][n];

	return 0;
}

