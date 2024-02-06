#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 51;
ll a[N], c[N];
vector<pii> v;

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int f,b;
	cin >> f >> b;
	for(int i=0; i<f; i++) cin >> a[i];
	for(int i=0; i<b; i++) cin >> c[i];
	for(int i=0; i<f; i++)
		for(int j=0; j<b; j++)
			v.emplace_back(a[i], c[j]);
	sort(v.begin(), v.end(), [](const pii &x, const pii &y) {
		ll c1 = x.first*y.second, c2 = y.first*x.second;
		if(c1==c2) return x.first<y.first;
		return c1<c2;
	});
	for(auto &e:v) cout << "(" << e.first << "," << e.second << ")" << "\n";

	return 0;
}
