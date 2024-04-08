#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1, mxN = 5, mod = 1e9+7;
ll dp[4][N];
/*
0->down
1->down long
2->up
3->up long
*/

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	dp[1][1]=2;
	dp[2][1]=1;
	for(int i=2;i<N;i++){
		dp[0][i]=dp[3][i-1];
		dp[1][i]=dp[1][i-1]+dp[0][i-1]*2%mod;
		dp[2][i]=dp[1][i-1];
		dp[3][i]=dp[2][i-1]*2%mod+dp[3][i-1];
		dp[0][i]%=mod;
		dp[1][i]%=mod;
		dp[2][i]%=mod;
		dp[3][i]%=mod;
	}
	int q; cin >> q;
	ll n;
	while(q--){
		cin >> n;
		cout << (dp[2][n]+dp[3][n])%mod << "\n";
	}
	
	return 0;
}
