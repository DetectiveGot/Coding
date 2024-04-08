#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
int qs[N], ask[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,q; cin >> n >> m >> q;
	for(int i=1;i<=n;i++){
		cin >> qs[i];
		qs[i]+=qs[i-1];
		ask[i]=-1;
	}
	int l=0,r;
	for(int i=1;i<=n;i++){
		while(l<n && qs[i]-qs[l]>m) ++l;
		if(qs[i]-qs[l]==m) ask[l+1]=i;
	}
	while(q--){
		cin >> l >> r;
		while(l<r && ask[l]==-1) ++l;
		if(ask[l]!=-1 && ask[l]<=r) cout << "Yes\n";
		else cout << "No\n";
	}
	
	return 0;
}
