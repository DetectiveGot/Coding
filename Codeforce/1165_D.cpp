#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

void solve(){
	ll t;
	int n; cin >> n;
	vector<ll> v(n),x;
	for(ll &e:v) cin >> e;
	sort(v.begin(), v.end());
	t=v[0]*v[n-1];
	for(int i=2;1LL*i*i<=t;i++){
		if(t%i==0){
			x.push_back(i);
			if(i^(t/i)) x.push_back(t/i);
		}
	}
	sort(x.begin(), x.end());
	if(x==v) cout << t;
	else cout << -1;
	cout << "\n";
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
// 3, 5, 16
