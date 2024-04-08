#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 1e5+1;
vector<int> g[N];
int al[N], ar[N], sg[N<<4], lz[N<<4], cnt=0;

void psh(int i, int l, int r){
	sg[i]+=lz[i];
	if(l<r){
		lz[i*2]+=lz[i];
		lz[i*2+1]+=lz[i];
	}
	lz[i]=0;
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

int qry(int i, int l, int r, int ql, int qr){
	psh(i, l, r);
	if(l>qr || r<ql) return 0;
	if(l>=ql && r<=qr) return sg[i];
	int mid = (l+r)/2;
	return qry(i*2, l, mid, ql, qr)+qry(i*2+1, mid+1, r, ql, qr);
}

void dfs(int u, int p){
	al[u]=++cnt;
	for(auto&e:g[u]){
		if(e==p) continue;
		dfs(e, u);
	}
	ar[u]=cnt;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,q,u,v,cmd,x; cin >> n >> q;
	for(int i=1;i<n;i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	for(int i=0;i<q;i++){
		cin >> cmd >> x;
		if(cmd==1) upd(1, 1, 1, n, al[x], ar[x]);
		else cout << (qry(1, 1, n, al[x], al[x])&1) << "\n";
	}
//	for(int i=1;i<=n;i++){
//		deb(i) << (qry(1, 1, n, al[i], al[i])&1) << "\n";
//	}
	
	return 0;
}
