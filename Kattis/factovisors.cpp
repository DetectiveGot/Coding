#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 46346;
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
	ll n,m,x;
	while(cin >> m >> n){
		if(n==0){
			cout << n << " does not divide " << m << "!\n";
			continue;
		}
		vector<pii> pr;
		x=n;
		for(auto &e:v){
			if(e*e>x) break;
			if(x%e==0){
				ll c=0;
				while(x%e==0) x/=e,++c;
				pr.emplace_back(e, c);
			}
		}
		if(x>1) pr.emplace_back(x, 1);
		bool ok=true;
		for(auto &e:pr){
			ll pw=e.first,c=0;
			while(m>=pw) c+=m/pw, pw*=e.first;
			if(c<e.second){
				ok=false;
				break;
			}
		}
		if(ok) cout << n << " divides " << m << "!\n";
		else cout << n << " does not divide " << m << "!\n";
	}

	return 0;
}

