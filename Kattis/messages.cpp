#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 5e4+1, mod = 1e9+7, p = 41, p1 = 101;
ll hsh[N], pw[N], pw1[N], hx[N];
vector<int> sz;
map<pii, bool> mp;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s;
	ll hs=0,hh=0;
	pw[0]=pw1[0]=1;
	for(int i=1;i<N;i++){
		pw[i]=pw[i-1]*p%mod;
		pw1[i]=pw1[i-1]*p1%mod;
	}
	while(cin >> s && s!="#"){
		hs=hh=0;
		for(int i=0;i<s.size();i++){
			hs=hs*p%mod+s[i]-'a'+1;
			hh=hh*p1%mod+s[i]-'a'+1;
		}
		sz.push_back(s.size());
		hs%=mod;
		hh%=mod;
		mp[{hs, hh}]=1;
	}
	int m = sz.size();
	char t;
	while(cin >> t && t!='#'){
		s+=t;
		if(t=='|'){
			int n=s.size(),ans=0,pv=-1; --n;
			vector<pii> v;
			for(int i=1;i<=n;i++){
				hsh[i]=hsh[i-1]*p%mod+s[i-1]-'a'+1;
				hsh[i]%=mod;
				hx[i]=hx[i-1]*p1%mod+s[i-1]-'a'+1;
				hx[i]%=mod;
				for(int j=0;j<m;j++){
					if(i-sz[j]<0) continue;
					hs = hsh[i]-hsh[i-sz[j]]*pw[sz[j]]%mod;
					hs%=mod, hs+=mod, hs%=mod;
					hh = hx[i]-hx[i-sz[j]]*pw1[sz[j]]%mod;
					hh%=mod, hh+=mod, hh%=mod;
					if(mp.count(make_pair(hs, hh))) v.emplace_back(i, i-sz[j]);
				}
			}
			sort(v.begin(), v.end());
			for(auto &e:v) if(e.second>=pv) ++ans, pv=e.first;
			cout << ans << "\n";
			s="";
		}
	}

	return 0;
}

