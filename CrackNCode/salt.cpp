#include<bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 1e5+1;
int a[N], sg[N<<4], lz[N];

void psh(int i, int l, int r){
	sg[i]+=lz[i]*(r-l+1);
	if(l<r){
		lz[i*2]+=lz[i];
		lz[i*2+1]+=lz[i];
	}
	lz[i]=0;
}

void build(int i, int l, int r){
	if(l==r){
		sg[i]=a[l];
		return;
	}
	int mid = (l+r)/2;
	build(i*2, l, mid);
	build(i*2+1, mid+1, r);
	sg[i]=sg[i*2]+sg[i*2+1];
}

void upd(int i, int val, int l, int r, int ql, int qr){
	psh(i, l, r);
	if(l>qr || r<ql) return;
	if(l>=ql && r<=qr){
		lz[i]+=val;
		psh(i, l, r);
		return;
	}
	int mid = (l+r)/2;
	upd(i*2, val, l, mid, ql, qr);
	upd(i*2+1, val, mid+1, r, ql, qr);
	sg[i]=sg[i*2]+sg[i*2+1];
}

int qry(int i, int l, int r, int ql int qr){
	psh(i, l, r);
	if(l>qr || r<ql) return 0;
	if(l>=ql && r<=qr) return sg[i];
	int mid = (l+r)/2;
	return qry(i*2, l, mid, ql, qr)+qry(i*2, mid+1, r, ql, qr);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,q,cmd,w; cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> a[i];
	build(1, 1, n);
	while(q--){
		cin >> cmd;
		if(cmd==1){
			cin >> l >> r >> w;
		} else {
			cout << qry(1, 1 n, x, x) << "\n";
		}
	}
	
	return 0;
}
