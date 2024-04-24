#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int &e:a) cin >> e;
	for(int &e:b) cin >> e;
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	for(int i=0;i<n;i++) b[i]+=a[i];
	sort(b.begin(), b.end());
	ll ans=0;
	for(int i=1;i<n;i++) ans+=b[i]-b[i-1];
	cout << ans;

	return 0;
}
