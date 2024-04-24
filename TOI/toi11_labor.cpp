#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+5;
ll a[N],m;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	ll l=0, r=1e12;
	while(l<r){
		ll md = l+r>>1ll, s=0;
		for(int i=0;i<n;i++){
			s+=md/a[i];
			if(s>=m) break;
		}
		if(s<m) l=md+1;
		else r=md;
	}
	cout << l;

	return 0;
}
