#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1;
ll fw[N];
vector<tpi> v;

inline void upd(int i, int val){
	for(;i<N;i+=i&-i) fw[i]+=val;
}

inline ll qry(int i){
	ll res=0;
	for(;i>=1;i-=i&-i) res+=fw[i];
	return res;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,t,s,h,w,o; cin >> n >> t;
	for(int i=0;i<n;i++){
		cin >> s >> h >> w >> o;
		v.emplace_back(s, h, o);
		v.emplace_back(s+w, h, -o);
	}
	sort(v.begin(), v.end());
	int sz = siz(v);
	ll ans=0;
	for(int i=0;i<sz-1;i++){
		tie(s, h, o) = v[i];
		upd(1, o);
		upd(h+1, -o);
		int l = 1, r = 1e6, lo, hi;
		while(l<r){
			int m = l+r>>1;
			if(qry(m)>t) l=m+1;
			else r=m;
		}
		lo = l;
		l = 1, r = 1e6;
		while(l<r){
			int m = l+r>>1;
			if(qry(m)>=t) l=m+1;
			else r=m;
		}
		hi = l;
//		deb(s), deb(h), deb(o), deb(hi), deb(lo) << "\n";
		ans+=(hi-lo)*(get<0>(v[i+1])-s);
	}
	cout << ans;

	return 0;
}
