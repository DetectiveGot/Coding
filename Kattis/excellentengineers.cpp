#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define ppi pair<pii, int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
int sg[N<<2];

inline void upd(int i, int p, int v, int l, int r){
	if(l==r) return void(sg[i]=v);
	int m = (l+r)>>1;
	if(p<=m) upd(i<<1, p, v, l, m);
	else upd(i<<1|1, p, v, m+1, r);
	sg[i]=min(sg[i<<1], sg[i<<1|1]);
}

inline int qry(int i, int l, int r, int ql, int qr){
	if(l>qr || r<ql) return 1e9;
	if(l>=ql && r<=qr) return sg[i];
	int m = (l+r)>>1;
	return min(qry(i<<1, l, m, ql, qr), qry(i<<1|1, m+1, r, ql, qr));
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc,n,a,b,c; ; cin >> tc;
	while(tc--){
		cin >> n;
		int ans=1,sz=n;
		vector<ppi> v(n);
		memset(sg, 0x3f, sizeof(sg));
		for(auto &e:v) cin >> e.first.first >> e.first.second >> e.second;
		sort(v.begin(), v.end());
		upd(1, v[0].first.second, v[0].second, 1, n);
		for(int i=1;i<n;i++){
			a=v[i].first.first, b=v[i].first.second, c=v[i].second;
			int qb = qry(1, 1, n, 1, b);
			if(a>=v[i-1].first.first && c>=qb) continue;
			upd(1, b, c, 1, n);
			++ans;
		}
		cout << ans << "\n";
	}	

	return 0;
}

