#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5+2, p=107;

//qs[r]-qs[l]==n*k
ll qs[N];
unordered_map<ll,int> mp;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	ll ans=0;
	mp[0]++;
	for(int i=1;i<=n;i++){
		cin >> qs[i];
		qs[i]+=qs[i-1];
		ans+=mp[(qs[i]%n+n)%n];
		mp[(qs[i]%n+n)%n]++;
	}
	cout << ans;
	
	return 0;
}
