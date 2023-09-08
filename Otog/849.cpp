#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,s=0,t; cin >> n;
	int mx=-1e9, mn=1e9,x=-1e9;
	for(int i=1;i<=n;i++){
    	cin >> t;
		s+=t;
		x=max(x, t);
		mn=min(mn, s-mx);
		mx=max(mx, s);
	}
	cout << max(x,s-mn);		
	
	return 0;
}
