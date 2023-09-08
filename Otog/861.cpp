#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 5e4+3;
ll qa[N], qb[N], qs[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,q; cin >> n >> q;
	ll k;
	for(int i=1;i<=n;i++) cin >> qa[i], qa[i]+=qa[i-1];
	for(int i=1;i<=n;i++) cin >> qb[i], qb[i]+=qb[i-1];
	qa[0]=-1e18, qb[0]=-1e18;
	for(int i=1;i<=n;i++){
		qa[i]=max(qa[i], qa[i-1]);
		qb[i]=max(qb[i], qb[i-1]);
		qs[i]=qa[i]+qb[i];
	}
	
	while(q--){
		cin >> k;
		cout << lower_bound(qs+1, qs+n, k)-qs << "\n";
	}
	
	return 0;
}
