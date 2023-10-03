#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1,lim=1e6;
bitset<N> p;

inline void solve(){
	ll n; cin >> n;
	ll sq=sqrt(n);
	if(sq*sq==n && !p[sq]) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int q; cin >> q;
	p[1]=1;
	for(int i=2;i*i<=lim;i++){
		if(p[i]) continue;
		for(int j=i*i;j<=lim;j+=i) p[j]=1;
	}
	while(q--) solve();
	
	return 0;
}
