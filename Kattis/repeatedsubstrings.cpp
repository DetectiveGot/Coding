#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int p = 107, p1 = 47, mod = 1e9+7;
int cnt[26];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s; cin >> s;
	int n=s.size(),l=0,r=n;
	string ans="";
	while(l<r){
		int m = (l+r+1)>>1;
		ll hs=0,hs1=0,pw=1,pw1=1;
		vector<tuple<int,int,int>> v;
		for(int i=0;i<m;i++){
			pw=pw*p%mod;
			hs=hs*p%mod+s[i]-'a'+1;
			pw1=pw1*p1%mod;
			hs1=hs1*p1%mod+s[i]-'a'+1;
		}
		hs%=mod;
		hs1%=mod;
		v.emplace_back(hs, hs1, 0);
		for(int i=m;i<n;i++){
			hs=hs*p%mod+s[i]-'a'+1;
			hs-=pw*(s[i-m]-'a'+1)%mod;
			hs%=mod, hs+=mod, hs%=mod;
			hs1=hs1*p1%mod+s[i]-'a'+1;
			hs1-=pw1*(s[i-m]-'a'+1)%mod;
			hs1%=mod, hs1+=mod, hs1%=mod;
			v.emplace_back(hs, hs1, i-m+1);
		}
		sort(v.begin(), v.end());
		bool ok=false;
		for(int i=1;i<v.size();i++){
			if(get<0>(v[i-1])==get<0>(v[i]) && get<1>(v[i-1])==get<1>(v[i])){
				string tmp=s.substr(get<2>(v[i-1]), m);
				if(ans.size()<tmp.size()) ans=tmp;
				else if(ans.size()==tmp.size() && ans>tmp) ans=tmp;
				ok=true;
			}
		}
		if(ok) l=m;
		else r=m-1;
	}
	cout << ans;

	return 0;
}
