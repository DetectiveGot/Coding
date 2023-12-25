#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2e5+1;
ll a[N], b[N], qs[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,sz=1; cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]>=0) b[sz]+=a[i];
		else {
			if(i^1) ++sz;
			b[sz]=a[i];
		}
	}
	ll ans=LLONG_MIN,s=0;
	for(int i=1;i<=sz;i++) qs[i]=qs[i-1]+abs(b[i]);
	for(int i=1;i<sz;i++){
		if(b[i]<0) ans=max(ans, s+b[i]-b[i+1]+qs[sz]-qs[i+1]);
		s+=b[i];
	}
	ans=max(ans, s);
	deb(sz) << endl;
//	cout << endl;
	for(int i=1;i<=sz;i++) cout << b[i] << " "; cout << endl;
//	for(int i=1;i<=sz;i++) cout << qs[i] << " "; cout << endl;
	cout << ans;
	
	
	return 0;
}
/*
11
3-2+7+1-3+5-7+7-9+8+6
*/
