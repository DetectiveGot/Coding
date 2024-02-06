#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2.1e5+1;
ll a[N];
unordered_set<ll> s;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	ll r1=1,mx=0;
	for(int i=1;i<=n;i++) cin >> a[i],mx=max(mx, a[i]);
	for(int i=1;i<=n;i++){
		if(mx%a[i]==0){
			if(s.count(a[i])) r1=r1/__gcd(r1, a[i])*a[i];
			else s.insert(a[i]);
		} else  r1=r1/__gcd(r1, a[i])*a[i];
	}
	cout << r1 << " " << mx;

	return 0;
}
/*
10
8 1 2 12 1 2 6 4 3 4
*/
