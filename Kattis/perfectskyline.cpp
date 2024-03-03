//start from sall
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 16, mxN = 32770;
ll a[N], h[N],n,s;
unordered_map<ll, int> pos;
vector<int> mp[mxN];
vector<int> ans;

inline void dfs(int i, int mask) {
	if(i==s) {
		for(auto &e:ans) {
			vector<int> x;
			for(int j=0; j<n; j++) if(e&1<<j) x.push_back(j+1);
			cout << x.size() << " ";
			for(auto &y:x) cout << y << " ";
			cout << "\n";
		}
		exit(0);
	}
	int p = pos[h[i]];
	for(auto &e:mp[p]) {
		if(!(e&mask)) {
			ans.push_back(e);
			dfs(i+1, mask|e);
			ans.pop_back();
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> n >> s;
	int id=0;
	ll sall=0;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<s; i++) {
		cin >> h[i];
		sall+=h[i];
		if(!pos.count(h[i])) pos[h[i]]=++id;
	}
	h[s]=sall;
	pos[h[s]]=0;
	for(int i=1; i<1<<n; i++) {
		ll sum=0;
		for(int j=0; j<n; j++) if(i&1<<j) sum+=a[j];
		if(pos.count(sum)) mp[pos[sum]].push_back(i);
	}
	for(int i=0; i<=s; i++) {
		if(mp[pos[h[i]]].empty()) {
			cout << -1;
			return 0;
		}
	}
	dfs(0, 0);
	cout << -1;

	return 0;
}
