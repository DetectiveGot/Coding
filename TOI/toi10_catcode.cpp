#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+3, mod = 1e6;
int hsh[N], id[N], p, fr,hs;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m; cin >> n >> m;
	string s;
	for(int i=1;i<=n;i++){
		cin >> s;
		hs=0;
		for(auto &e:s) hs=(hs<<1)+e-'0';
		p = hs%mod;
		while(id[p]){
			++p;
			if(p>=mod) p-=mod;
		}
		id[p]=i;
		hsh[i]=hs;
	}
	int q,sz; cin >> q;
	while(q--){
		vector<bool> ch(n+1);
		cin >> sz >> s;
		fr=1<<m-1;
		hs=0;
		bool ok=false;
		for(int i=0;i<m-1;i++) hs=(hs<<1)+s[i]-'0';
		for(int i=m-1;i<sz;i++){
			hs=(hs<<1)+s[i]-'0';
			p=hs%mod;
			while(id[p]){
				if(hsh[id[p]]==hs){
					ok=true;
					ch[id[p]]=1;
					break;
				}
				++p;
				if(p>=mod) p-=mod;
			}
			hs-=fr&hs;
		}
		if(!ok) cout << "OK\n";
		else {
			for(int i=1;i<=n;i++) if(ch[i]) cout << i << " ";
			cout << "\n";
		}
	}

	return 0;
}

