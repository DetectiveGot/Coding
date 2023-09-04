#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+2;
int cnt[N], mx[N];

void solve(){
	string s; cin >> s;
	int n=s.size(),ans=0,mn=1e9;
	for(char i='a';i<='z';i++){
		int c=0,mx=0;
		for(char&e:s){
			c++;
			if(e==i) c=0;
			mx=max(mx, c);
		}
		mn=min(mn, mx);
	}
	while(mn){
		mn>>=1;
		ans++;
	}
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}
