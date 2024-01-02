#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2e5+1;
vector<ll> x;
ll dp[N];
struct DATA{
	ll l,r,w;
	bool operator < (const DATA &dt) const{
		return r<dt.r;
	}
};
vector<DATA> v;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	ll n,l,r; int k;
	cin >> n >> k;
	for(int i=0;i<k;i++){
		cin >> l >> r;
		v.push_back({l,r,r-l+1});
	}
	x.push_back(0);
	sort(v.begin(), v.end());
	for(int i=1;i<=k;i++){
		int it = lower_bound(x.begin(), x.end(), v[i-1].l)-x.begin();
		--it;
		dp[i]=max(dp[i-1], dp[it]+v[i-1].w);
		x.push_back(v[i-1].r);
	}
	cout << n-dp[k];
	
	return 0;
}
