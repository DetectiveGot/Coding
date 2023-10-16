#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e4+1, K = 9;
ll dp[1<<K|1];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,k; cin >> n >> k;
	for(int i=0;i<1<<k;i++) dp[i]=1e9;
	for(int i=0;i<n;i++){
		ll val,t,hs=0; cin >> val;
		for(int j=0;j<k;j++) cin >> t, hs=(hs<<1)+t;
		dp[hs]=min(dp[hs], val);
	}
	for(int i=1;i<1<<k;i++){
		for(int j=1;j<i;j++){
			dp[i|j]=min(dp[i|j], dp[i]+dp[j]);
		}
	}
	cout << dp[(1<<k)-1];
	
	return 0;
}
