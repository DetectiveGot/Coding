#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>

using namespace std;

const ll p1 = 41, p2 = 101, mod = 1e9+7;
string s;

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n;
	cin >> n;
	cin >> s;
	int l=0, r=n;
	while(l<r) {
		int m = (l+r+1)>>1;
		bool ok=false;
		ll hs1=0, hs2=0, fr1=1, fr2=1;
		vector<pii> mp;
		for(int i=0; i<m; i++) {
			hs1=hs1*p1%mod+s[i]-'a', fr1=fr1*p1%mod;
			hs2=hs2*p2%mod+s[i]-'a', fr2=fr2*p2%mod;
		}
		hs1%=mod;
		hs2%=mod;
		mp.push_back({hs1,hs2});
		for(int i=m; i<n; i++) {
			hs1=hs1*p1%mod+s[i]-'a';
			hs2=hs2*p2%mod+s[i]-'a';
			hs1-=fr1*(s[i-m]-'a')%mod;
			hs2-=fr2*(s[i-m]-'a')%mod;
			hs1+=mod, hs1%=mod;
			hs2+=mod, hs2%=mod;
			mp.push_back({hs1,hs2});
		}
		sort(mp.begin(), mp.end());
		for(int i=1; i<mp.size(); i++) {
			if(mp[i]==mp[i-1]) {
				ok=true;
				break;
			}
		}
		if(ok) l=m;
		else r=m-1;
	}
	cout << l;

	return 0;
}
