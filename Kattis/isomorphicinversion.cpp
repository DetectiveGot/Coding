#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1, p = 41, mod = 1e9+7;
ll pw[N], hsh[N];

inline ll cal(const ll l, const ll r){
	return ((hsh[r]-hsh[l]*pw[r-l]%mod)%mod+mod)%mod;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s; cin >> s;
	int n=s.size(),ans=0;
	pw[0]=1;
	for(int i=1;i<N;i++) pw[i]=pw[i-1]*p%mod;
	for(int i=1;i<=n;i++) hsh[i]=hsh[i-1]*p%mod+s[i-1]-'0', hsh[i]%=mod;
	int l=0,m=n>>1;
	for(int i=1;i<=m;i++) if(cal(l,i)==cal(n-i, n-l)) ++ans, l=i;
	ans<<=1;
	if(n&1 || l!=m) ++ans;
	cout << ans;

	return 0;
}

