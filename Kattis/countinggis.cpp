#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1, mod = 1e9+7;
int gis[N];
bool use[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	ll l,ans=1,c=0;
	int n; cin >> n >> l;
	for(int i=1;i<=l;i++){
		cin >> gis[i];
		if(!use[gis[i]]) use[gis[i]]=1;
		else {
			cout << 0;
			return 0;
		}
	}
	if(gis[l]!=n || !is_sorted(gis+1, gis+l+1)){
		cout << 0;
		return 0;
	}
	for(int i=n;i>=1;--i){
		if(use[i]) continue;
		ll p = lower_bound(gis+1, gis+l+1, i)-gis;
		ans=ans*(l-p+1+c)%mod;
		++c;
	}
	cout << ans;

	return 0;
}

