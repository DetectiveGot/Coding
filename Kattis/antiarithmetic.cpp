#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
int mp[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	string s;
	int n;
	while(cin >> s && s!="0") {
		n=0;
		int idx=0,t;
		memset(mp, 0, sizeof(mp));
		while(s[idx]!=':') n=n*10+s[idx++]-'0';
		bool ok=true;
		for(int i=1;i<=n;i++) cin >> t, mp[t]=i;
		for(int i=1;i<n && ok;i++){
			for(int j=0;j<n-2*i;j++){
				if(mp[j]<mp[j+i] ^ mp[j+i]>mp[j+2*i]){
					ok=false;
					break;
				}
			}
		}
		if(ok) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}
