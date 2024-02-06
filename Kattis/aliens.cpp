#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 4e4+1, p = 41, p1 = 113, mod = 1e9+7;
ll hsh[N], pw[N], hx[N], pw1[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int x;
	pw[0]=pw1[0]=1;
	for(int i=1;i<N;i++){
		pw[i]=pw[i-1]*p%mod;
		pw1[i]=pw1[i-1]*p1%mod;
	}
	while(cin >> x && x!=0){
		string s; cin >> s;
		int n=s.size();
		for(int i=1;i<=n;i++){
			hsh[i]=hsh[i-1]*p%mod+s[i-1]-'a'+1, hsh[i]%=mod;
			hx[i]=hx[i-1]*p1%mod+s[i-1]-'a'+1, hx[i]%=mod;
		}
		int l=0,r=n,ans=-1;
		while(l<r){
			int m = (l+r+1)>>1, mx=-1;
			vector<tuple<int,int,int>> v;
			for(int i=m;i<=n;i++){
				ll hs = hsh[i]-hsh[i-m]*pw[m]%mod;
				hs%=mod, hs+=mod, hs%=mod;
				ll hs1 = hx[i]-hx[i-m]*pw1[m]%mod;
				hs1%=mod, hs1+=mod, hs1%=mod;
				v.emplace_back(hs, hs1, i-m);
			}
			sort(v.begin(), v.end());
			int c=1;
			bool ok=false;
			for(int i=1;i<v.size();i++){
				if(get<0>(v[i-1])==get<0>(v[i]) && get<1>(v[i-1])==get<1>(v[i])) ++c;
				else c=1;
				if(c>=x) ok=true, mx=max(mx, get<2>(v[i]));
			}
			if(c>=x) mx=max(mx, get<2>(v.back())), ok=true;
			if(ok) l=m,ans=mx;
			else r=m-1;
		}
		if(l==0) cout << "none\n";
		else cout << l << " " << ans << "\n";
	}

	return 0;
}

