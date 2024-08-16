#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1;
ll dp[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	ll n,mod; cin >> n >> mod;
	dp[3]=1;
	for(ll i=4;i<=n;i++){
		dp[i]=dp[i-1]*(i-1)%mod+dp[i-3]*(((i-1)*(i-2)/2)%mod)%mod;
		dp[i]%=mod;
	}
	cout << dp[n];

	return 0;
}