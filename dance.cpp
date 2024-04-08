#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5+2;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	ll mx=0;
	vector<ll> a(n), b(n);
	for(ll &e:a) cin >> e;
	for(ll &e:b) cin >> e;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for(int i=0;i<n;i++) mx=max(mx, abs(a[i]-b[i]));
	cout << mx;
	
	return 0;
}
