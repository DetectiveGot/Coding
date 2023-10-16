#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const ll mod = 1e9+7;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	ll n; cin >> n;
	n%=mod;
	cout << n*n%mod*n%mod;
	
	return 0;
}
