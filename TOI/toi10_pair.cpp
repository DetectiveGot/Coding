#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1001;
int dp[N][N];
char a[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int d=1;d<n;d++){
		for(int i=1,j=i+d;i<=n-d;i++,j++){
			if(a[i]==a[j]) dp[i][j]=dp[i+1][j-1]+1;
			else for(int k=i;k<j;k++) dp[i][j]=max(dp[i][j], dp[i][k]+dp[k+1][j]);
		}
	}
	cout << dp[1][n];

	return 0;
}

