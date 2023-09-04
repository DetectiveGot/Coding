#include<bits/stdc++.h>

using namespace std;

const int N = 3002, mod = 1e9+7;
int dp[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,cnt=0; cin >> n;
	dp[0]=1;
	for(int i=1;i<=n;i++) (dp[i]=dp[i-1]*i)%=mod;
	string s; cin >> s;
	for(auto&e:s){
		if(e=='<') cnt++; 
	}
	cout << dp[n]/(((long long)dp[n-cnt]*dp[cnt]))%mod;
	
	return 0;
}
