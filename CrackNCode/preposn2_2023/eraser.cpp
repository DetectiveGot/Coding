#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;
const int N = 32;
vector<pii> v;

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	ll n,k,c0,p,c;
	cin >> n >> k >> c0;
	for(int i=0; i<k; i++) {
		cin >> p >> c;
		v.push_back({c, p});
	}
	v.push_back({c0, 0});
	sort(v.begin(), v.end(), [](pii x, pii y) {
		return x.first*(1<<y.second)<y.first*(1<<x.second);
	});
	ll ans=0;
	for(auto &e:v) {
		ans+=n/(1<<e.second)*e.first;
		n%=(1<<e.second);
	}
	cout << ans;

	return 0;
}