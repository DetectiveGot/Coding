#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	string s[n];
	for(int i=0;i<n;i++) cin >> s[i];
	sort(s,s+n);
	for(auto&e:s) cout << e << "\n";
	
	return 0;
}
