#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	ll n,m;
	for(int i=0;i<20;i++){
		cin >> m >> n;
		ll x = m-2*n,ans=0;
		if(x<0 || x&1){
			cout << "0\n";
			continue;
		}
		x>>=1;
		ll yz=4*n-m;
		if(yz<0 || yz&1){
			cout << "0\n";
			continue;
		}
		ans=yz>>1;
		ans++;
		cout << ans << "\n";
	}

	return 0;
}
