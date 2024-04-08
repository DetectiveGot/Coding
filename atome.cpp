#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 1e5+2;
ll al[N], ar[N], fw[N], cnt=0;
bool st[N];
vector<int> g[N];

void upd(int i, int val){
  for(;i<=100000;i+=i&-i) fw[i]+=val;
}

ll qry(int i){
  ll res=0;
  for(;i>=1;i-=i&-i) res+=fw[i];
  return res;
}

void dfs(int u, int p){
  al[u]=cnt;
  for(auto&e:g[u]){
    if(e==p) continue;
    dfs(e, u);
  }
  ar[u]=++cnt;
  upd(ar[u], 1);
}

int main(){
  // ios::sync_with_stdio(0); cin.tie(0);
  int n,q,u,v,cmd,x; cin >> n >> q;
  for(int i=1;i<n;i++){
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, -1);
  while(q--){
    cin >> cmd >> x;
    if(cmd==1){
      if(qry(ar[x]-qry(al[x]))) upd(al[x], -1);
      else upd(al[x], 1);
//      cout << "DEBUG\n";
    } else {
      cout << qry(ar[x]-qry(al[x])) << "\n";
      // cout << "DEBUG\n";
    }
  }

  return 0;
}
