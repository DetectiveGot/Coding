#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,t; cin >> n;
	cin >> t;
	int mx=t, mn=0, s=t;
	for(int i=2;i<=n;i++){
    	cin >> t;
		s+=t;
		mn=min(mn, s-mx);
		mx=max(mx, s);
	}
	cout << s-mn;	
	
	return 0;
}
