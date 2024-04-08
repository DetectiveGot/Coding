#include<bits/stdc++.h>

using namespace std;

const int N = 5e4+1;
map<int, vector<int>> mp;
set<int> s;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,q,l,r,t; cin >> n;
	for(int i=0;i<n;i++){
		cin >> t, mp[t].push_back(i);
		s.insert(t);
	}
	cin >> q;
	while(q--){
		cin >> l >> r;
		int il, ir, cnt=0;
		for(auto&e:s){
			if(mp[e].size()<=1) continue;
			il=lower_bound(mp[e].begin(), mp[e].end(), l)-mp[e].begin();
			ir=upper_bound(mp[e].begin(), mp[e].end(), r)-mp[e].begin();
			cnt+=(ir-il)>1;
		}
		cout << cnt << "\n";
	}
	
	return 0;
}
