#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
int a[N];
struct DATA{
	int mx;
} sg[4*N];

void upd(int i, int idx, int val, int l, int r, int st){
	if(l==r){
		sg[i].mx=val+(l-st)*;
		return;
	}
	int mid=(l+r)/2;
	if(idx<=mid) upd(1, idx, val, l, mid);
	else upd(1, idx, val, mid+1, r);
	sg[i].mx=max(sg[i*2].mx, sg[i*2+1].mx);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,q; cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		upd(1, i, a[i], 1, n, 0, 0);
	}
	
	return 0;
}
