#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1;
const ll mod = 1e9+7, p = 41, p1 = 113;
ll pw[N], pw1[N], hsh[N], hh[N];
map<pii, bool> mp;
vector<string> vs;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	pw[0]=pw1[0]=1;
	for(int i=1;i<N;i++){
		pw[i]=pw[i-1]*p%mod;
		pw1[i]=pw1[i-1]*p1%mod;
	}
	ll hs=0,hs1=0;
	string s;
	for(int i=1;i<=n;i++){
		cin >> s;
		vs.push_back(s);
		hs=hs1=0;
		for(auto &e:s) hs=hs*p%mod+e-'a'+1,hs1=hs1*p1%mod+e-'a'+1;
		hs%=mod;
		hs1%=mod;
		mp[{hs,hs1}]=1;
	}
	bool ok=false;
	for(int q=0;q<n;q++){
		hsh[0]=hh[0]=0;
		int sz=vs[q].size();
		for(int i=1;i<=sz;i++){
			hsh[i]=hsh[i-1]*p%mod+vs[q][i-1]-'a'+1, hsh[i]%=mod;
			hh[i]=hh[i-1]*p1%mod+vs[q][i-1]-'a'+1, hh[i]%=mod;
		}
		for(int i=1;i<=sz;i++){
			hs1=hh[sz]-hh[i]*pw1[sz-i]%mod+hh[i-1]*pw1[sz-i]%mod;
			hs=hsh[sz]-hsh[i]*pw[sz-i]%mod+hsh[i-1]*pw[sz-i]%mod;
			hs1%=mod, hs1+=mod, hs1%=mod;
			hs%=mod, hs+=mod, hs%=mod;
			if(mp.count(make_pair(hs, hs1))){
				ok=true;
				cout << vs[q] << "\n";
				break;
			}
		}
	}
	if(!ok) cout << "NO TYPOS";

	return 0;
}

