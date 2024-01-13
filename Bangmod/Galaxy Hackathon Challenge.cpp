//credit: Khlui
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int m, n, ans=0; cin >> m >> n;
	int ar[n]; memset(ar, 0, sizeof ar);
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			int x; cin >> x;
			ar[j]=max(ar[j], x);
		}
	}
	for(int i=0;i<n;i++) {
		ans+=ar[i];
	}
	cout << ans;
	return 0;
}
