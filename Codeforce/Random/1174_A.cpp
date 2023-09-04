#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> v(n), ch(26, -1);
	for(int& e:v) cin >> e;
	string s; cin >> s;
	bool ok=true;
	for(int i=0;i<n;i++){
		if(ch[s[i]-'a']==-1) ch[s[i]-'a']=v[i];
		if(ch[s[i]-'a']!=v[i]){
			ok=false;
//			break;
		}
	}
	if(ok) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
