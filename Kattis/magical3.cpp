#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 46341;
bool p[N];
vector<ll> v;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	for(int i=2;i*i<N;i++){
		if(p[i]) continue;
		for(int j=i*i;j<N;j+=i) p[j]=1;
	}
	v.push_back(2);
	for(int i=3;i<N;i+=2) if(!p[i]) v.push_back(i);
	ll n;
	while(cin >> n && n!=0){
//	for(int n=1;n<=500;n++){
		if(n<=6){
			if(n==3) cout << "4\n";
			else cout << "No such base\n";
		} else {
			ll ans=LLONG_MAX,x=n-3;
			vector<ll> m{1};
			for(auto &e:v){
				if(e*e>x) break;
				if(x%e==0){
					while(x%e==0) x/=e;
					m.push_back(e);
				}
			}
			if(x>1) m.push_back(x);
//			for(auto &e:m) cout << e << " "; cout << endl;
			int sz=min(4, (int)m.size());
			x=n-3;
			for(int i=0;i<sz;i++){
				for(int j=0;j<sz;j++){
					ll tmp = m[i]*m[j];
					if(tmp>3  && x%tmp==0 && ans>tmp) ans=tmp;
				}
			}
			if(ans==LLONG_MAX) cout << "No such base\n";
			else cout << ans << "\n";
		}
	}
	
	return 0;
}
