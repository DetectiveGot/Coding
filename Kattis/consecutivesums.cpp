#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc; cin >> tc;
	auto cal = [](ll x){
		return (x*(x+1))>>1;
	};
	while(tc--){
		ll n; cin >> n;
		ll l=1,r=n;
		while(l<r){
			ll m = (l+r)/2;
			if(n-((m-1)*m)/2>=0) l=m+1;
			else r=m;
		}
		if(l){
			cout << n << " = ";
			for(int i=n-((l-1)*l)/2;i<=n;i++) cout << i << " + ";
			cout << "\n";
		} else cout << "IMPOSSIBLE\n";
	}

	return 0;
}

