#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+3, dx[]= {1,0,-1,0}, dy[]= {0,-1,0,1};
ll pa[N], sz[N], n,m;
struct DATA {
	ll x,y,w,use;
	bool operator < (const DATA &dt) const {
		if(w==dt.w) return use<dt.use;
		return w > dt.w;
	}
};
vector<DATA> v;

inline int hsh(int x, int y) {
	--x;
	return x*m+y;
}

inline int fp(int x) {
	if(pa[x]==x) return x;
	return pa[x]=fp(pa[x]);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	ll k,all=0;
	cin >> n >> m >> k;
	ll a[n+1][m+1] {0};
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> a[i][j];
			pa[hsh(i,j)]=hsh(i,j);
			sz[hsh(i,j)]=1;
			v.push_back({i,j,a[i][j],0});
			v.push_back({i,j,a[i][j]+k,1});
		}
	}
	sort(v.begin(), v.end());
	ll ans=0;
	for(auto &e:v) {
		ll siz=0;
		unordered_set<int> mp;
		for(int i=0; i<4; i++) {
			int x=e.x+dx[i], y=e.y+dy[i];
			if(x<1 || y<1 || x>n || y>m || e.w>a[x][y]) continue;
			int pu = fp(hsh(e.x, e.y)), pv = fp(hsh(x, y));
			if(pu==pv) continue;
			if(!e.use){
				if(sz[pu]<sz[pv]) swap(pu, pv);
				pa[pv]=pu;
				sz[pu]+=sz[pv];
			} else {
				if(mp.count(pv)) continue;
				siz+=sz[pv];
				mp.insert(pv);
			}
		}
		if(!e.use) ans=max(ans, sz[fp(hsh(e.x, e.y))]*e.w);
		else {
			siz+=sz[fp(hsh(e.x, e.y))];
			ans=max(ans, siz*e.w);
		}
	}
	cout << ans;

	return 0;
}