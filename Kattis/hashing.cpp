#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 3e5+1, mod = 1e9+7, p1 = 41, p2 = 101;
ll h1[N], h2[N], pw1[N], pw2[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s; cin >> s;
	int n=s.size(),q,l,r; cin >> q;
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=n;i++){
		h1[i]=h1[i-1]*p1%mod+s[i-1]-'a'+1;
		h2[i]=h2[i-1]*p2%mod+s[i-1]-'a'+1;
		pw1[i]=pw1[i-1]*p1%mod;
		pw2[i]=pw2[i-1]*p2%mod;
		h1[i]%=mod, h2[i]%=mod;
	}
	while(q--){
		cin >> l >> r;
		ll hs1,hs2;
		hs1=h1[r]-h1[l]*pw1[r-l]%mod;
		hs2=h2[r]-h2[l]*pw2[r-l]%mod;
		hs1%=mod, hs1+=mod, hs1%=mod;
		hs2%=mod, hs2+=mod, hs2%=mod;
		hs1=hs1*1ll*1e9+hs2;
		cout << hs1 << "\n";
	}

	return 0;
}

