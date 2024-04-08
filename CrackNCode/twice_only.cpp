#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1;
ll dp[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,mod; cin >> n >> mod;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			dp[i]+=dp[j]*dp[i-j-1]%mod;
			dp[i]%=mod;
		}
	}
	cout << dp[n];
	
	return 0;
}
