#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5+2;
ll arr[N];

struct node{
	ll mn;
} a[2*N];

void upd(int l, int i, int x, int il, int ir){
	if(il==ir){
		a[i].mn=x;
		return;
	}
	int mid=(il+ir)/2;
	if(l<=mid) upd(l, i*2, x, il, mid);
	else upd(l, i*2+1, x, mid+1, ir);
	a[i].mn=min(a[i*2].mn, a[i*2+1].mn);
}

ll query(int i, int l, int r, int il, int ir){
	if(l<=il && ir<=r) return a[i].mn;
	int mid=(il+ir)/2;
	return min((l<=mid?query(i*2, l, r, il, mid):1e9),(r>mid?query(i*2+1, l, r, mid+1, ir):1e9));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,q; cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> arr[i], upd(i, 1, arr[i], 1, n);
	while(q--){
		int l,r; cin >> l >> r;
		cout << query(1, l, r, 1, n) << "\n";
	}
	
	return 0;
}
