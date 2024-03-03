#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 101, p = 41, mod = 1e9+7;

vector<pii> v;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int q,n; cin >> q;
	string s,t;
	cin >> s;
	n=s.size();
	for(int i=0;i<n;i++){
		t="";
		ll hs=0;
		for(int j=i;j<n;j++){
			hs=hs*p%mod+s[j]-'a'+1;
			hs%=mod;
			v.push_back({hs,j-i+1});
		}
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end())-v.begin());
	for(int x=1;x<q;x++){
		cin >> s;
		n=s.size();
		vector<pii> st;
		for(int i=0;i<n;i++){
			ll hs=0;
			for(int j=i;j<n;j++){
				hs=hs*p%mod+s[j]-'a'+1;
				hs%=mod;
				pii tmp = {hs, j-i+1};
				auto it = lower_bound(v.begin(), v.end(), tmp);
				if(it!=v.end() && it->first==hs && it->second==j-i+1) st.push_back({hs,j-i+1});
			}
		}
		sort(st.begin(), st.end());
		st.resize(unique(st.begin(), st.end())-st.begin());
		v=st;
	}
	ll mx=0;
	for(auto &e:v) mx=max(mx, e.second);
	cout << mx;

	return 0;
}

