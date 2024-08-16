#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
ll a[N], b[N], c[N], d[N], ac[N], bd[N];
set<pii> s;
vector<pii> vec;

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) cin >> b[i];
	for(int i=1; i<=n; i++) cin >> c[i];
	for(int i=1; i<=n; i++) cin >> d[i];
	for(int i=1; i<=n; i++) {
		ac[i]=ac[i-1]+a[i]-c[i]; //x
		bd[i]=bd[i-1]+b[i]-d[i]; //y
		vec.emplace_back(ac[i], bd[i]);
	}
	vec.emplace_back(0,0);
	sort(vec.begin(), vec.end());
	ll d, ans = LLONG_MAX;
	int l=0;
	for(int i=0; i<=n; i++) {
		d = sqrt(ans);
		while(vec[i].first-vec[l].first>d) {
			s.erase({vec[l].second, vec[l].first});
			++l;
		}
		auto lo = s.lower_bound({vec[i].second-d-1, vec[i].first});
		auto hi = s.upper_bound({vec[i].second+d, vec[i].first});
		for(auto it = lo; it!=hi; ++it) {
			ll x = it->second-vec[i].first, y = it->first-vec[i].second;
			ll cal = x*x+y*y;
			ans=min(ans, cal);
		}
		s.insert({vec[i].second, vec[i].first});
	}
	cout << ans;

	return 0;
}