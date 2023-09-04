#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
int a[N], qs[N];

struct DATA{
	int mx;
} sg[4*N];

void upd(int i, int idx, int val, int l, int r){
	if(l==r){
		sg[i].mx=val;
		return;
	}
	int mid=(l+r)/2;
	if(idx<=mid) upd(i*2, idx, val, l, mid);
	else upd(i*2+1, idx, val, mid+1, r);
	sg[i].mx=max(sg[i*2].mx, sg[i*2+1].mx);
}

int query(int i, int ql, int qr, int l, int r){
	if(l>qr || r<ql) return -1e9;
	if(l>=ql && r<=qr) return sg[i].mx;
	int mid=(l+r)/2;
	return max(query(i*2, ql, qr, l, mid), query(i*2+1, ql, qr, mid+1, r));
}

void solve(){
	int n,mx=-1e9,l=1; cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		upd(1, i, a[i], 1, n);
		if(i-l+1>=3) mx=max(mx, a[l]+l+query(1, l+1, i-1, 1, n)+a[i]-i);
		if(i-l+1>=3 && a[i]+i>=a[l]+l) l=i;
	}
	cout << mx << "\n";
	memset(sg, 0, sizeof(sg));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--) solve();
	
	return 0;
}
