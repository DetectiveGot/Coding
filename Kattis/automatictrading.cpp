#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1, p = 41, p1 = 113, mod = 1e9+7;
ll hsh[N], pw[N], hx[N], pw1[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	string s;
	cin >> s;
	pw[0]=pw1[0]=1;
	int n=s.size();
	for(int i=1; i<=n; i++) {
		pw[i]=pw[i-1]*p%mod;
		hsh[i]=hsh[i-1]*p%mod+s[i-1]-'A'+1;
		hsh[i]%=mod;
		pw1[i]=pw1[i-1]*p1%mod;
		hx[i]=hx[i-1]*p1%mod+s[i-1]-'A'+1;
		hx[i]%=mod;
	}
	int q;
	cin >> q;
	int x,y,l,r;
	while(q--) {
		cin >> x >> y;
		++x,++y;
		l=0,r=min(n-y+1, n-x+1);
		while(l<r) {
			int m = (l+r+1)>>1;
			ll lt = hsh[x+m-1]-hsh[x-1]*pw[m]%mod, rt = hsh[y+m-1]-hsh[y-1]*pw[m]%mod;
			lt%=mod,lt+=mod,lt%=mod;
			rt%=mod,rt+=mod,rt%=mod;
			ll lt1 = hx[x+m-1]-hx[x-1]*pw1[m]%mod, rt1 = hx[y+m-1]-hx[y-1]*pw1[m]%mod;
			lt1%=mod,lt1+=mod,lt1%=mod;
			rt1%=mod,rt1+=mod,rt1%=mod;
			if(lt==rt && lt1==rt1) l=m;
			else r=m-1;
		}
		cout << l << "\n";
	}

	return 0;
}
