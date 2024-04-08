#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << "]: " << x << " "

using namespace std;
const int N = 1e6+2;
ll qs[N];
deque<int> dq;

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	ll n,m,l,u,x,p;
	cin >> n >> m >> l >> u;
	for(int i=0; i<m; i++) {
		cin >> p >> x;
		qs[p]=x;
	}
	int pt = 0;
	ll ans=0;
	dq.push_back(0);
	for(int i=1; i<=n; i++) {
		qs[i]+=qs[i-1];
		while(!dq.empty() && i-dq.front()>2*u+1) dq.pop_front();
		while(!dq.empty() && i-dq.front()>2*l+1 && qs[dq.back()]>qs[i-2*l-1]) dq.pop_back();
		if(i-2*l-1>0) dq.push_back(i-2*l-1);
		if(!dq.empty()) ans=max(ans, qs[i]-qs[dq.front()]);
	}
	cout << ans;

	return 0;
}
/*
18 5 2 4
2 1
8 2
14 -2
16 -1
18 6

12 6 0 1
2 -1
4 3
6 -2
8 5
10 3
12 2
*/
