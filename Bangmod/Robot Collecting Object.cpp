//credit: khlui
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int y, x, ans=0; cin >> y >> x;
	int ar[y+2][x+2]; memset(ar, 0, sizeof ar);
	for(int i=1;i<=y;i++) {
		for(int j=1;j<=x;j++) {
			int temp; cin >> temp;
			ar[i][j]=max(ar[i-1][j],ar[i][j-1])+temp;
			ans=max(ans, ar[i][j]);
		}
	}
	cout << ans;
	return 0;
}
