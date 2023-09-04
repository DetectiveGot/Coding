#include<bits/stdc++.h>
#define ll long long

using namespace std;

//qs[r]-qs[l-1]==k -> qs[l-1]=qs[r]-k
const int N = 2e5+2;
ll qs[N];
unordered_map<ll, ll> mp;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,x; cin >> n >> x;
	mp[qs[0]]++;
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin >> qs[i];
		qs[i]+=qs[i-1];
		ans+=mp[qs[i]-x];
//		cout << i << " map: " << qs[i]-x << " " << mp[qs[i]-x] << "\n";
		mp[qs[i]]++;
	}
	cout << ans;
	
	return 0;
}
