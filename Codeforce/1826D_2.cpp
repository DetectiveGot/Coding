#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+2;
int a[N], p[N], s[N];

void solve(){
	int n,mx=-1e9; cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		p[i]=max(p[i-1], a[i]+i);
	}
	s[n+1]=-1e9;
	for(int i=n;i>=1;--i) s[i]=max(s[i+1], a[i]-i);
	for(int i=2;i<n;i++) mx=max(mx, p[i-1]+a[i]+s[i+1]);
	cout << mx << "\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}
