#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 5e5+1;
pii a[N];
ll qs[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	ll mn = 1e18,pos=0,ans=1e18,sum=0;
	for(int i=1;i<=n;i++) cin >> a[i].second, mn = min(mn, a[i].second);
	for(int i=1;i<=n;i++) cin >> a[i].first;
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++) qs[i]=qs[i-1]+a[i].first;
	for(int i=1;i<=n;++i){
		if(a[i].first>mn) break;
		ll cal = qs[n]-qs[i]-a[i].first*(n-i);
		cal+=qs[i-1]+sum-a[i].first*(i-1);
		sum+=a[i].second;
		if(cal<ans) ans=cal, pos=a[i].first;
	}
	cout << pos << " " << ans;

	return 0;
}
