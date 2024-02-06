#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 51;
int cost[]={6,2,5,5,4,5,6,3,7,6};
int a[N];
unordered_map<ll,ll> mp;

inline ll dfs(int n){
	if(n<8){
		for(int i=1;i<=9;i++) if(n==cost[i]) return i;
		return 10;
	}
	if(mp.count(n)) return mp[n];
	ll ans=LLONG_MAX;
	for(int i=0;i<=9;i++) if(n-cost[i]>=0) ans=min(ans,dfs(n-cost[i])*10+i);
	return mp[n]=ans;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		cout << dfs(n) << " ";
		if(n&1){
			cout << 7;
			for(int i=0;i<(n-3)>>1;i++) cout << 1;
		} else for(int i=0;i<n>>1;i++) cout << 1;
		cout << "\n";
	}

	return 0;
}

