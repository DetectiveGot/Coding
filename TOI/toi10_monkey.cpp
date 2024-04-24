#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2e5+2;
int a[N];
vector<pii> v;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,k,p,h; cin >> m >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=0;i<k;i++){
		cin >> p >> h;
		v.push_back({h, p});
	}
	sort(v.begin(), v.end());
	for(int i=k-1;i>=0;--i) swap(a[v[i].second], a[v[i].second+1]);
	int s; cin >> s;
	int ans=a[s], ans2=max(a[s-1], a[s+1]);
	for(auto &[h, p]:v){
		swap(a[p], a[p+1]);
		if(s==p) s=p+1;
		else if(s==p+1) s=p;
		ans2=max({ans2, a[s-1], a[s+1]});
	}
	if(ans>=ans2) cout << ans << "\nNO";
	else cout << ans2 << "\nUSE";

	return 0;
}
