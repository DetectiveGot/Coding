#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+2;

void solve(){
	int n,q; cin >> n >> q;
	vector<int> dp(n+1);
	for(int i=1;i<=n;i++) cin >> dp[i], dp[i]+=dp[i-1];
	int l,r,k;
	while(q--){
		cin >> l >> r >> k;
		if((dp[r]-dp[l-1]-k*(r-l+1)+dp[n])&1) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
	
}

/*
6
8

*/
