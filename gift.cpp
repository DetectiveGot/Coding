#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2e4+1;
ll w[N], h[N], dp[N], qs[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int q,n; cin >> q;
	while(q--){
		ll l,sum=0; cin >> n >> l;
		deque<ll> dq;
		for(int i=1;i<=n;i++) cin >> w[i], qs[i]=qs[i-1]+w[i];
		for(int i=1;i<=n;i++) cin >> h[i];
		for(int i=1;i<=n;i++){
			while(!dq.empty() && qs[i]-qs[dq.front()-1]>l) dq.pop_front();
			while(!dq.empty() && h[i]>=h[dq.back()]) dq.pop_back();
			dq.push_back(i);
			int it = lower_bound(qs, qs+dq.front(), qs[i]-l)-qs;
			dp[i]=dp[it]+h[dq.front()];
			for(int j=1;j<dq.size();j++) dp[i]=min(dp[i], dp[dq[j-1]]+h[dq[j]]);
		}
		cout << dp[n] << "\n";
	}
	
	return 0;
}
