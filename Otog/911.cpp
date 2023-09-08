#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 301, K = 10, mod = 1e9+7;
ll qs[N], dp[K][N][N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,k,d; cin >> n >> k >> d;
	for(int i=1;i<=n;i++) cin >> qs[i], qs[i]+=qs[i-1];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			dp[1][i][j]=1;
	for(int lvl=2;lvl<=k;lvl++){
		for(int s=0;s<n;s++){
			for(int i=1;i<=n-s;i++){
				int j=i+s;
				for(int m=i;m<j;m++){
					ll s1=qs[j]-qs[m], s2=qs[m]-qs[i-1];
					if(abs(s1-s2)<=d){
						dp[lvl][i][j]+=dp[lvl-1][i][m]*dp[lvl-1][m+1][j]%mod;
						dp[lvl][i][j]%=mod;
					}
				}
			}
		}
	}
	cout << dp[k][1][n];
	
	return 0;
}
/*
13 3 5
8 7 4 2 8 5 3 5 2 5 3 7 7
*/
