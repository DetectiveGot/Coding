#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
const double EPS = 1e-7;
pii a[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	double ds,dx;
	ll x,y,r,d;
	int tc,n; cin >> tc;
	auto cal = [](const pii l, const pii r)->double{
		ll xx = l.first-r.first, yy = l.second-r.second;
		xx*=xx, yy*=yy;
		double res = sqrt(xx+yy);
		return res;
	};
	while(tc--){
		cin >> n >> r >> d;
		for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
		sort(a, a+n);
		set<pii> s;
		int l=0;
		ds = 1e18;
		for(int i=0;i<n;i++){
			while(a[i].first-a[l].first>ds){
				s.erase({a[l].second, a[l].first});
				++l;
			}
			auto it=s.lower_bound({a[i].second-ds, a[i].first});
			for(auto j = it;j!=s.end() && j->first<=a[i].second+ds;j++){
				dx = cal(make_pair(it->second, it->first), a[i]);
				ds = min(dx, ds);
			}
			s.insert({a[i].second, a[i].first});
		}
		if(ds-2*r<d) cout << "N\n";
		else cout << "Y\n";
	}

	return 0;
}
