#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 31623;
bool p[N];
vector<int> v;

inline void solve(){
	int n; cin >> n;
	auto cal = [](int x){
		int s=0;
		while(x){
			s+=x%10;
			x/=10;
		}
		return s;
	};
	while(1){
		++n;
		bool ok=false;
		int t=n,s=0;
		for(auto &e:v){
			if(e*e>t) break;
			while(t%e==0) t/=e, s+=cal(e),ok=true;
		}
		if(t>1) s+=cal(t);
		if(cal(n)==s && ok){
			cout << n << "\n";
			return;
		}
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int q; cin >> q;
	for(int i=2;i*i<N;i++){
		if(p[i]) continue;
		for(int j=i*i;j<N;j+=i) p[j]=1;
	}
	v.push_back(2);
	for(int i=3;i<N;i+=2)
		if(!p[i]) v.push_back(i);
	while(q--) solve();
	
	return 0;
}
