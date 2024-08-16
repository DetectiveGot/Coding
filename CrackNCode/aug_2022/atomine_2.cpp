#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 1e5+1;
vector<int> g[N];
int al[N], ar[N], sg[N<<4], lz[N<<4], cnt=0;

void psh(int i){
  sg[i*2]+=lz[i];
  lz[i*2]+=lz[i];
  sg[i*2+1]+=lz[i];
  lz[i*2+1]+=lz[i];
  lz[i]=0;
}
void upd(int i, int l, int r, int ql, int qr, int val){
  if(ql>qr) return;
  if(ql==l && qr==r){
    lz[i]+=val;
    sg[i]+=val;
    return;
  } else {
    int mid = (l+r)/2;
    psh(i);
    upd(i*2, l, mid, ql, min(qr, mid), val);
    upd(i*2+1, mid+1, r, max(ql, mid+1), qr, val);
    sg[i]=sg[i*2]+sg[i*2+1];
  }
}
int qry(int i, int l, int r, int ql, int qr){
  if(ql>qr) return 0;
  if(ql==l && qr==r) return sg[i];
  psh(i);
  int mid = (l+r)/2;
  return max(qry(i*2, l, mid, ql, min(qr, mid)),qry(i*2+1, mid+1, r, max(ql, mid+1), qr));
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
		if(cmd==1){
			upd(1, 1, n, al[x], ar[x], 1);
		} else {
			cout << (qry(1, 1, n, al[x], al[x])&1) << "\n";
		}
	}
//	for(int i=1;i<=n;i++){
//		deb(i) << !(qry(1, 1, n, al[x], al[x])&1) << endl;
//	}
	
	return 0;
}