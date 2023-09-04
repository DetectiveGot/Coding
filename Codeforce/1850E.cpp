#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << "]: " << x << " "

using namespace std;

const int N = 2e5+2;
ll a[N];

void solve(){
	int n; cin >> n;
	ll c,t,s=0; cin >> c;
	for(int i=1;i<=n;i++) cin >> a[i];
	ll l=0, r=1e9;
	while(l<r){
		ll mid = (l+r+1)/2;
		s=0;
		for(int i=1;i<=n;i++){
			s+=(2*mid+a[i])*(2*mid+a[i]);
			if(s>c){
				r=mid-1;
				break;;
			}
		}
		if(s<=c) l=mid;
		else r=mid-1;
	}
	cout << l << "\n";
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}
