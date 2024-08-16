#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;
const int N = 5e5+5;
ll a[N], b[N], color[N], qs[N];
deque<ll> mn,mx;

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	ll n,p,x,y,z;
	cin >> n >> p >> x >> y >> z;
	for(int i=1; i<=n; i++) cin >> a[i], qs[i]=qs[i-1]+a[i];
	for(int i=1; i<=n; i++) cin >> b[i];
	ll ans=0;
	int l=1;
	for(int i=1; i<=n; i++) {
		color[b[i]]++;
		if(y!=-1) {
			while(!mn.empty() && a[i]<=a[mn.back()]) mn.pop_back();
			mn.push_back(i);
			while(!mx.empty() && a[i]>=a[mx.back()]) mx.pop_back();
			mx.push_back(i);
			while(!mn.empty() && !mx.empty() && a[mx.front()]-a[mn.front()]>y) {
				color[b[l]]--;
				++l;
				while(!mn.empty() && mn.front()<l) mn.pop_front();
				while(!mx.empty() && mx.front()<l) mx.pop_front();
			}
		}
		while(qs[i]-qs[l-1]>x) color[b[l]]--,++l;
		if(z!=-1) while(color[b[i]]>z) color[b[l]]--, ++l;
		while(!mn.empty() && mn.front()<l) mn.pop_front();
		while(!mx.empty() && mx.front()<l) mx.pop_front();
		ans+=i-l+1;
	}
	cout << ans;

	return 0;
}