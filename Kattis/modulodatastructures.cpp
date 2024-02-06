#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2e5+1;
int ar[N], ab[101][101];

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,q;
	cin >> n >> q;
	int t,a,b,c,d;
	for(int i=0; i<q; i++) {
		cin >> t;
		if(t==1) {
			cin >> a >> b >> c;
			if(b<=100) ab[a][b]+=c;
			else for(int i=a; i<=n; i+=b) ar[i]+=c;
		} else {
			cin >> d;
			int ans=0;
			for(int i=1; i<=100; i++) ans+=ab[d%i][i];
			ans+=ar[d];
			cout << ans << "\n";
		}
	}

	return 0;
}

