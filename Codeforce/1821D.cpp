#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

bool cmp(const pii &l, const pii &r){
	if(l.first==r.first) return l.second>r.second;
	return l.first < r.first;
}

void solve(){
	int n,k; cin >> n >> k;
	vector<pii> v(n);
	for(auto&e:v) cin >> e.first >> e.second;
	sort(v.begin(), v.end(), cmp);
	int prv=0;
	for(int i=0;i<v.size();i++){
		if()
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--) solve();
	
	return 0;
}
