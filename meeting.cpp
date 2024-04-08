#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
vector<pii> p;
int dp[N];
struct DATA{
	int l,r,i;
	bool operator < (const DATA &dt) const{
		if(l==dt.l) return r>dt.r;
		return l<dt.l;
	}
};
vector<DATA> v;
struct A{
	int l,r,w;
	bool operator < (const A &dt) const{
		return r<dt.r;
	}
};
vector<A> vec;
map<int,int> mp;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,l,r; cin >> n;
	for(int i=0;i<n;i++){
		cin >> l >> r;
		v.push_back({l,r,i});
	}
	sort(v.begin(), v.end());
	for(auto &e:v){
		auto it = lower_bound(p.begin(), p.end(), make_pair(e.l, e.i));
		if(it==p.end()) p.push_back({e.l, e.i});
		else dp[(*it).second]++;
	}
	for(auto &e:p) vec.push_back({e.first, v[e.second].r, dp[e.second]});
	sort(vec.begin(), vec.end());
	mp[0]=0;
	int mx=0;
	for(auto &e:vec){
		int st=e.l, ed=e.r, ww=e.w;
		auto it = mp.lower_bound(st);
		--it;
		mx=max(mx, ww+it->second);
		mp[ed]=mx;
	}
	cout << mx;
	
	return 0;
}
