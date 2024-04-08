#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 1e5+1;
ll a[N], sg[N<<4];

void build(int i, int l, int r){
	if(l==r) return void(sg[i]=a[l]);
	int mid = (l+r)/2;
	build(i*2, l, mid);
	build(i*2+1, mid+1, r);
	sg[i]=max(sg[i*2], sg[i*2+1]);
}

ll qry(int i, int l, int r, int ql, int qr){
	if(l>qr || r<ql) return 0;
	else if(l>=ql && r<=qr) return sg[i];
	int mid = (l+r)/2;
	return max(qry(i*2, l, mid, ql, qr), qry(i*2+1, mid+1, r, ql, qr));
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	ll m;
	int n,q,l,r; cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	build(1, 1, n);
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	cin >> q;
	while(q--){
		cin >> l >> r;
		ll x = qry(1, 1, n, l, r),y=a[r]-a[l-1];
		--y;
		y/=m;
		++y;
		cout << max(x, y) << "\n";
	}
	
	return 0;
}
