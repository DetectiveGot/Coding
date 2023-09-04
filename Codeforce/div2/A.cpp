#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
	int n; cin >> n;
	ll res=1;
	for(int i=1;i<=n;i++){
		int t; cin >> t;
		res*=t;
	}
	cout << (res+n-1)*2022 << "\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
