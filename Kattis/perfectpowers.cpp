#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 50001;
bool p[N];
vector<ll> v;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	for(ll i=2;i*i<N;i++){
		if(p[i]) continue;
		for(ll j=i*i;j<N;j+=i) p[j]=1;
	}
	v.push_back(2);
	for(ll i=3;i<N;i+=2) if(!p[i]) v.push_back(i);
	ll n;
	while(cin >> n && n!=0){
		ll t = abs(n), gcd=0,ans;
		for(auto &e:v){
			if(e*e>t) break;
			ll c=0;
			while(t%e==0) t/=e, ++c;
			if(!gcd) gcd=c;
			if(c) gcd=__gcd(gcd, c);
		}
		if(t>1) gcd=1;
		ans=gcd;
		if(n<0) for(int i=1;i<=gcd;i+=2) if(gcd%i==0) ans=i;
		cout << ans << "\n";
	}
	
	return 0;
}
