#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1, mxN = 2e5+1;
ll a[N], b[N], qs[mxN];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<ll> v;

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) cin >> b[i];
	for(int i=1;i<=n;i++) pq.push({a[i], i});
	v.push_back(0);
	while(!pq.empty()){
		auto [w, id] = pq.top();
		pq.pop();
		v.push_back(w);
		if(id!=-1) pq.push({b[id], -1});
	}
	int sz = siz(v);
	for(int i=1;i<sz;i++) qs[i]=qs[i-1]+v[i];
	int q, mx=n<<1;
	cin >> q;
	ll x;
	while(q--) {
		cin >> x;
		int pos = upper_bound(qs, qs+mx+1, x)-qs-1;
		cout << pos << "\n";
	}

	return 0;
}