#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int mod = 1e9+7;

inline ll bp(ll a, ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	ll x,y; cin >> x >> y;
	x%=mod, y%=mod;
	cout << (x-3)%mod*(x-4)%mod*bp(y-1, mod-2)%mod;
	
	return 0;
}
