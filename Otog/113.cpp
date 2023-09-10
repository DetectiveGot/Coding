#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
int dp[N], a[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	++n;
	for(int i=4;i<=n;i++){
		dp[i]=max(dp[i-1], dp[i-3]+a[i-1]);
//    deb(i); deb(dp[i]) << endl;
	}
	cout << dp[n];
	
	return 0;
}
