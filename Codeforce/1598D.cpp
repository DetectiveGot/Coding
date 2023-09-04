#include<bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>

using namespace std;
const int N = 2e5+2;
int mp[N], mp2[N];

//fixed one

void solve(){
	int n; cin >> n;
	vector<pii> v(n);
	for(pii&e:v) cin >> e.first >> e.second, mp[e.first]++, mp2[e.second]++;
	ll c=(1LL*n*(n-1)*(n-2))/6;
	for(pii&e:v) c-=(mp[e.first]-1)*(mp2[e.second]-1)*1LL;
	cout << c << "\n";
	for(int i=1;i<=n;i++) mp[i]=mp2[i]=0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}
//https://codeforces.com/contest/1598
