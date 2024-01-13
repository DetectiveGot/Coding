//SCORE: 12/15
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;
vector<int> v[2];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,p; cin >> n >> m >> p;
	int q; cin >> q;
	int lvl,st;
	while(q--){
		cin >> lvl >> st;
		v[st].push_back(lvl);
	}
	v[0].push_back(0);
	v[1].push_back(0);
	sort(v[0].begin(), v[0].end());
	v[0].resize(unique(v[0].begin(), v[0].end())-v[0].begin());
	sort(v[1].begin(), v[1].end());
	v[1].resize(unique(v[1].begin(), v[1].end())-v[1].begin());
	int s0=v[0].size(),s1=v[1].size();
	if(p==1){
		int pos = lower_bound(v[1].begin(), v[1].end(), m)-v[1].begin();
		for(int i=pos;i<s1;i++) cout << v[1][i] << "u ";
		for(int i=s0-1;i>=1;--i) cout << v[0][i] << "d ";
		for(int i=1;i<pos;i++) cout << v[1][i] << "u ";
	} else {
		int pos = lower_bound(v[0].begin(), v[0].end(), m)-v[0].begin();
		for(int i=min(pos, s0-1);i>=1;--i) cout << v[0][i] << "d ";
		for(int i=1;i<s1;i++) cout << v[1][i] << "u ";
		for(int i=pos+1;i<s0;++i) cout << v[0][i] << "d ";
	}
	
	return 0;
}
