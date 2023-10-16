#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int mod = 10001, N = 1001;
int dp[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
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
