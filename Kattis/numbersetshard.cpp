#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1;
bool p[N];
vector<int> v;
unordered_map<ll, bool> mp;
int pa[N];

inline int fp(int x){
	if(pa[x]==x) return x;
	return pa[x]=fp(pa[x]);
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	for(int i=2;i*i<N;i++){
		if(p[i]) continue;
		for(int j=i*i;j<N;j+=i) p[j]=1;
	}
	v.push_back(2);
	for(int i=3;i<N;i+=2) if(!p[i]) v.push_back(i);
	int tc; cin >> tc;
	while(tc--){
		ll a,b,p; cin >> a >> b >> p;
		for(ll i=a;i<=b;i++){
			ll t = i;
			int cnt=0;
			for(auto &e:v){
				if(e*e>t) break;
				if(t%e==0){
					++cnt;
					while(t%e==0) t/=e;
				}
			}
			if(t>1) ++cnt;
			if(cnt>=p){
				for(int j=i;j<=b;j+=i)
			}
		}
	}
	
	return 0;
}
