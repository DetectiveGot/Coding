#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
ll qs[N], qw[N], a[N], b[N];
deque<int> dq;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,p; cin >> n >> m >> p;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
		qs[i]=qs[i-1]+a[i];
		qw[i]=qw[i-1]+b[i];
	}
	ll ans=-1e18;
	for(int i=1;i<=n;i++){
		while(!dq.empty() && i-dq.front()>m) dq.pop_front();
		while(!dq.empty() && b[i]>=b[dq.back()]) dq.pop_back();
		dq.push_back(i);
		if(i<m) continue;
		ll l=b[dq.front()],r=qw[i]-qw[i-m];
		while(l<r){
			ll mid = l+r>>1, c=0;
			ll it = i-m;
			while(it<i){
				it = upper_bound(qw+it, qw+i+1, mid+qw[it])-qw-1;
				++c;
			}
			if(c>p) l=mid+1;
			else r=mid;
		}
		ans=max(ans, qs[i]-qs[i-m]-l*l);
	}
	cout << ans;

	return 0;
}
