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
	char c;
	int mul=1, z=1;
	for(int i=1;i<=2*n-1;i++){
		if(i&1){
			cin >> a[z];
			a[z]*=mul;
			if(i!=2*n-1) z++;
		} else {
			cin >> c;
			if(c=='-') mul=-1;
			else mul=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]>=0){
			if(a[i-1]<0) ++sz;
			b[sz]+=a[i];
		} else {
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
	s+=b[sz];
	ans=max(ans, s);
	cout << ans;
	
	return 0;
}
