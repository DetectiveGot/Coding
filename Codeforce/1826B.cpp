#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
int a[N];

void solve(){
	int n,mx=1; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	bool ok=true;
	mx=abs(a[n]-a[1]);
	for(int i=1;i<=n/2;i++){
		if(a[i]^a[n-i+1]){
			ok=false;
			break;
		}
	}
	if(ok){
		cout << "0\n";
		return;
	}
	for(int i=2;i<=n/2;i++) mx=__gcd(abs(a[n-i+1]-a[i]), mx);
	cout << mx << "\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}
