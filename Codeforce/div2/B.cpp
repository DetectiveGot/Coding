#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int mod=1e9+7;

void solve(){
	ll n,res=1; cin >> n;
	res=(n*2022)/6;
	res*=(4*n-1)%mod*(n+1)%mod;
	cout << res%mod << "\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
