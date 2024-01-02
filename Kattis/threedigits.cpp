#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int mod = 1000;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	ll n; cin >> n;
	ll res=1,_5=0,_2=0,pw=2,r=n%mod;
	while(n>=pw) _2+=n/pw, pw*=2;
	pw=5;
	while(n>=pw) _5+=n/pw, pw*=5;
	pw=2;
	for(int i=3;i<=n;i++){
		ll t=i;
		while(t%5==0) t/=5;
		while(t%2==0) t>>=1;
		res=res*t%mod;
	}
	_2-=_5;
	pw=2;
	while(_2>0){
		if(_2&1) res=res*pw%mod, res%=mod;
		pw=pw*pw%mod;
		_2>>=1;
	}
	if(n<7){
		cout << res;
		return 0;
	}
	if(res<10) cout << "00" << res;
	else if(res<100) cout << "0" << res;
	else cout << res;
	
	return 0;
}
