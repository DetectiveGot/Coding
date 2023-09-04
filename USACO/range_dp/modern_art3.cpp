#include<bits/stdc++.h>

using namespace std;

const int N = 302;
int a[N], dp[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n; cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=1e9;
	for(int i=1;i<=n;i++) cin >> a[i], dp[i][i]=1;
	for(int d=0;d<n;d++){
		for(int i=1;i<=n-d;i++){
			int j=i+d;
			for(int k=i;k<j;k++){
				if(a[i]==a[j]) dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]-1);
				else dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]);
			}
		}
	}
	cout << dp[1][n];
	
	return 0;
}
