#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s; ll k; cin >> s >> k;
	ll n=0,c=0;
	bool ok=false;
	for(auto &e:s){
		if(e!='.') n=n*10+e-'0';
		else ok=true;
		if(ok) ++c;
	}
	--c;
	ll t = n;
	for(int i=0;i<k;i++) t/=10;
	n-=t;
	ll x = pow(10, k)-1;
	x*=pow(10, c-k);
	ll gd = __gcd(n, x);
	cout << n/gd << "/" << x/gd;

	return 0;
}

