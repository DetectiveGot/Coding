#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

/*
0-0 2
0-1 1
0-2 0
1-0 2
1-1 1
1-2 1
2-0 1
2-1 2
2-2 1
*/

const int N = 256;
bool dp[N][N][3];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0); cout.tie(0);
	int tc=20,n;
	string s;
	while(tc--){
		memset(dp, false, sizeof(dp));
		cin >> n >> s;
		s="."+s;
		for(int i=1;i<=n;i++) dp[i][i][s[i]-'0']=1;
		for(int d=1;d<n;d++){
			for(int i=1,j=i+d;i<=n-d;i++,j++){
				for(int k=i;k<j;k++){
					if(dp[i][k][0] && dp[k+1][j][0]) dp[i][j][2]=1;
					if(dp[i][k][0] && dp[k+1][j][1]) dp[i][j][1]=1;
					if(dp[i][k][0] && dp[k+1][j][2]) dp[i][j][0]=1;
					if(dp[i][k][1] && dp[k+1][j][0]) dp[i][j][2]=1;
					if(dp[i][k][1] && dp[k+1][j][1]) dp[i][j][1]=1;
					if(dp[i][k][1] && dp[k+1][j][2]) dp[i][j][1]=1;
					if(dp[i][k][2] && dp[k+1][j][0]) dp[i][j][1]=1;
					if(dp[i][k][2] && dp[k+1][j][1]) dp[i][j][2]=1;
					if(dp[i][k][2] && dp[k+1][j][2]) dp[i][j][1]=1;
				}
			}
		}
		if(dp[1][n][0]) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}
