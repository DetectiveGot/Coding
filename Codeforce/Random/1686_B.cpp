#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,cnt=0; cin >> n;
	vector<int> v(n+1);
	for(int i=1;i<=n;i++) cin >> v[i];
	for(int i=1;i<=n;i++)
		if(v[i]<v[i-1]) cnt++,++i;
	cout << cnt << "\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
