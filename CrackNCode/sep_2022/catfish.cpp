#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2e6+2;
ll qs[N];
int v[N];
deque<int> dq;
set<int> s;
unordered_map<int,ll> mp;

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	ll n,m,l,u,p,x;
	cin >> n >> m >> l >> u;
	for(int i=0; i<m; i++) {
		cin >> p >> x;
		mp[p]=x;
		s.insert(p);
		s.insert(p-1);
		if(p+2*u+1<=n) {
			s.insert(p+2*u+1);
			s.insert(p+2*u);
		}
	}
	m=s.size();
	int i=1;
	for(auto &e:s) {
		if(!mp.count(e))  mp[e]=0;
		qs[i]+=qs[i-1]+mp[e];
		v[i]=e;
		i++;
	}

	int pt = 0;
	ll ans=0;
	for(int i=1; i<=m; i++) {
		while(dq.size()>1 && v[i]-v[dq.front()]>2*u+1) dq.pop_front();
		while(v[i]-v[pt]>2*l+1) {
			while(!dq.empty() && qs[dq.back()]>qs[pt]) dq.pop_back();
			dq.push_back(pt), pt++;
		}
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