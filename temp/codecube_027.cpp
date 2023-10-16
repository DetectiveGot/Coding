#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1<<20|1;
ll dp[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	ll hs=0,t;
	for(int i=1;i<=n;i++) cin >> t, hs=hs<<1|t;
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	dp[hs]=0;
	for(int j=0;j<n;j++){
		for(int i=(1<<20)-1;i>=0;--i){
			ll lt, m=1<<j, rt=1<<(j+1);
			lt=(j?1<<(j-1):0);
			ll pv;
			if(j) pv=i^lt^rt^m;
			else if(j==n-1) pv=i^lt^m;
			else if(j==0) pv=i^m^rt;
			dp[i]=min(dp[i], dp[pv]+1);
		}
	}
	cout << (dp[0]>=1e9?0:dp[0]);
	
	return 0;
}
