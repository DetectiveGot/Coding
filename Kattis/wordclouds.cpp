#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 5001;
int dp[N], w[N], h[N], qs[N];
deque<int> dq;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,l; cin >> n >> l;
	for(int i=1;i<=n;i++){
		cin >> w[i] >> h[i];
		qs[i]=qs[i-1]+w[i];
		while(!dq.empty() && qs[i]-qs[dq.front()-1]>l) dq.pop_front();
		while(!dq.empty() && h[i]>=h[dq.back()]) dq.pop_back();
		dq.push_back(i);
		int it = lower_bound(qs, qs+i, qs[i]-l)-qs;
		dp[i]=dp[it]+h[dq.front()];
		for(int j=1;j<dq.size();j++) dp[i]=min(dp[i], dp[dq[j-1]]+h[dq[j]]);
	}
	cout << dp[n];
	
	return 0;
}
