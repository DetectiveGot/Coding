#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 1e9+7, p = 47;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,k; cin >> n >> k;
	string s; cin >> s;
	int l=1,r=n;
	while(l<r){
		int m=(l+r+1)/2;
		ll hs=0,fr=1;
		bool ok=false;
		unordered_map<ll,ll> mp;
		for(int i=0;i<m;i++){
			hs=hs*p%mod+s[i]-'a';
			hs%=mod;
			fr=fr*p%mod;
		}
		mp[hs]++;
		if(mp[hs]<k){
			for(int i=m;i<n;i++){
				hs=hs*p%mod+s[i]-'a';
				hs-=fr*(s[i-m]-'a');
				hs%=mod;
				mp[hs]++;
				int x=mp[hs];
				if(x>=k){
					ok=true;
					break;
				}
			}
		} else ok=true;
		if(ok) l=m;
		else r=m-1;
	}
	cout << l;
	
	return 0;
}
