#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
int a[N], b[N];
vector<int> v;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	for(int i=n;i>=1;--i){
		ll x = b[i]-a[i];
		if(x<0) continue;
		auto it = upper_bound(v.begin(), v.end(), x);
		if(it==v.end()) v.push_back(x);
		else *it=x;
	}
	cout << v.size();

	return 0;
}
