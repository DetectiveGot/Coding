#include<bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,l,r; cin >> n >> m;
	vector<int> v(n);
	for(auto &e:v) cin >> e;
	while(m--){
		cin >> l >> r;
		vector<int> tmp;
		for(int i=l;i<=r;i++) tmp.push_back(v[i]);
		sort(tmp.begin(), tmp.end());
		for(auto &e:tmp) cout << e << " ";
		cout << "\n";
	}
	
	return 0;
}
