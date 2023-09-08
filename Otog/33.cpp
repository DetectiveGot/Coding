#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5+1;
ll a[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	ll m;
	int n; cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	ll l=1, r=1e18;
	while(l<r){
		ll mid=(l+r)/2,s=0;
		for(int i=0;i<n;i++) s+=mid/a[i];
		if(s<m) l=mid+1;
		else r=mid;
	}
	cout << l;
	
	return 0;
}
