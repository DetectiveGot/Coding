#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+2;
int a[N], b[N];

void solve(){
	int n,c=0,l=0,r=0,mx=0; cin >> n;
	a[n+1]=b[n+1]=0;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	for(int i=1;i<=n;i++){
		if(a[i]^b[i]){
			l=r=i;
			break;
		}
	}
	while(l>1 && b[l]>=b[l-1]) --l;
	while(r<n && b[r+1]>=b[r]) ++r;
	cout << l << " " << r << "\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}
