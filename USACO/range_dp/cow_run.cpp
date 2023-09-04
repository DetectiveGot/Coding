/*
LANG: C++17
PROB: The Cow Run
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 1002;
int a[N], dp[N][N][2];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("cowrun.in", "r", stdin);
	freopen("cowrun.out", "w", stdout);
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j][0]=dp[i][j][1]=1e9;
	for(int d=0;d<n;d++){
		for(int i=1;i<=n-d;i++){
			int j=i+d, rem=n-(j-i);
			if(i==j) dp[i][i][0]=dp[i][i][1]=abs(a[i])*n;
			else {
				if(i<n){
					dp[i][j][0]=min(dp[i][j][0], dp[i+1][j][0]+abs(a[i+1]-a[i])*rem);
					dp[i][j][0]=min(dp[i][j][0], dp[i+1][j][1]+abs(a[j]-a[i])*rem);
				}
				if(j>=1){
					dp[i][j][1]=min(dp[i][j][1], dp[i][j-1][0]+abs(a[j]-a[i])*rem);
					dp[i][j][1]=min(dp[i][j][1], dp[i][j-1][1]+abs(a[j]-a[j-1])*rem);
				}
			}
		}
	}	
	cout << min(dp[1][n][0], dp[1][n][1]);
	
	return 0;
}
