#include<bits/stdc++.h>
#define db double

using namespace std;

const int N = 105;

void solve(){
	vector<db> v;
	db n,mx=-1e9,mn=1e9; cin >> n;
	while(n--){
		db t; cin >> t;
		v.push_back(t);
		mx=max(mx,t);
		mn=min(mn,t);
	}
	for(auto&e:v) cout << e << " ";
	cout << "\nMin>=sqrt(Max) -> " << (mn>=sqrt(mx)?"True\n":"False\n");
	cout << "Max -> " << mx << " " << "\nMin -> " << mn << "\n\n";
	return;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
