#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
int a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		int s=0,n,mx=-2e9; cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i], s+=a[i];
		for(int i=2;i<=n;i++) mx=max(mx, s-2*a[i]-2*a[i-1]);
		cout << mx << "\n";
	}
	
	return 0;
}
