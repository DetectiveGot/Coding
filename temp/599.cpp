#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	vector<pii> v(n);
	for(auto &e:v) cin >> e.first >> e.second;
	sort(v.begin(), v.end(), [&](const pii &a, const pii &b)->bool{
		if(a.first==b.first) return a.second>b.second;
		return a.first<b.first;
	});
	for(auto &e:v) cout << e.first << " " << e.second << "\n";
	
	return 0;
}
