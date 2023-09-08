#include<bits/stdc++.h>

using namespace std;

vector<int> e,o;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		int t; cin >> t;
		if(t&1) o.push_back(t);
		else e.push_back(t);
	}
	sort(e.begin(), e.end());
	sort(o.begin(), o.end(), greater<int>());
	for(auto&r:e) cout << r << " ";
	for(auto&r:o) cout << r << " ";
	
	return 0;
}
