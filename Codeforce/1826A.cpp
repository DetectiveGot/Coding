#include<bits/stdc++.h>

using namespace std;

const int N = 102;
int a[N];

void solve(){
	int n,ans=0; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=n;i>=0;--i){ //liar
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(i<a[j]) cnt++;
		}
		if(cnt==i){
			cout << i << "\n";
			return;
		}
	}
	cout << "-1\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}
