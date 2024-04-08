#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;
vector<ll> v;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,k,t; cin >> n >> k;
	ll s=0, ans=0;
	v.push_back(0);
	for(int i=1;i<=n;i++){
		cin >> t;
		s+=t;
		auto it = upper_bound(v.begin(), v.end(), s-k), pos = lower_bound(v.begin(), v.end(), s);
		ans+=it-v.begin();
		v.insert(it, s);
	}
	cout << ans;
	
	return 0;
}
