#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 101;
int a[N][N][N], dp[N][N][N];
bool ok[N][N][N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,f,ans=0; cin >> n >> m >> f;
	ok[1][1][1]=1;
	for(int i=1;i<=f;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				cin >> a[i][j][k];
				ok[i][j][k]|=dp[i][j-1][k];
				ok[i][j][k]|=dp[i][j][k-1];
				if(a[i-1][j][k]<0){
					ok[i][j][k]|=dp[i-1][j][k];
					if(ok[i][j][k]) dp[i][j][k]=max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]})+abs(a[i][j][k]);
				} else if(ok[i][j][k]) dp[i][j][k]=max(dp[i][j-1][k], dp[i][j][k-1])+abs(a[i][j][k]);
			}
		}
		ans=max(ans, dp[i][n][m]);
	}
	cout << ans;
	
	return 0;
}
