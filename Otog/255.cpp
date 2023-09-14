#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
int ar[N], al[N], sg[N<<4], lz[N<<4], id=0;
vector<int> g[N];

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
	int mid=(l+r)/2;
	upd(i*2, val, l, mid, ql, qr);
	upd(i*2+1, val, mid+1, r, ql, qr);
	sg[i]=sg[i*2]+sg[i*2+1];
}

int qry(int i, int l, int r, int ql, int qr){
	psh(i, l, r);
	if(l>qr || r<ql) return 0;
	if(l>=ql && r<=qr) return sg[i];
	int mid=(l+r)/2;
	return qry(i*2, l, mid, ql, qr)+qry(i*2+1, mid+1, r, ql, qr);
}

void dfs(int u, int p){
	al[u]=++id;
	for(auto &e:g[u]){
		if(e==p) continue;
		dfs(e, u);
	}
	ar[u]=id;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,u,v,x,y; cin >> n >> m;
	for(int i=1;i<n;i++){
		cin >> u >> v;
		g[v].push_back(u);
	}
	dfs(1, -1);
	while(m--){
		cin >> x >> y;
		upd(1, y, 1, n, al[x], ar[x]);
	}
	for(int i=1;i<=n;i++) cout << qry(1, 1, n, al[i], al[i]) << "\n";
	
	return 0;
}
