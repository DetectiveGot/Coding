#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 5e5+1;
int a[N], dp[N];
deque<int> dq;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,k; cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		while(!dq.empty() && i-dq.front()>k) dq.pop_front();
		while(!dq.empty() && dp[dq.front()]+a[i]<dp[dq.back()]) dq.pop_back();
		dq.push_back(i);
		dp[i]=dp[dq.front()]+a[i];
	}
	cout << dp[n];
	
	return 0;
}

