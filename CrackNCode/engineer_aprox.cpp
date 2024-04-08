#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+2;
int pa[N];

int fp(int x){
  if(pa[x]==x) return x;
  return pa[x]=fp(pa[x]);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,r,p,u,v; cin >> n >> r >> p;
  iota(pa+1, pa+n+1, 1);
  for(int i=0;i<r;i++){
    cin >> u >> v;
    int pu=fp(u), pv=fp(v);
    if(pu==pv) continue;
    pa[pv]=pu;
  }
  while(p--){
    cin >> u >> v;
    if(fp(u)==fp(v)) cout << "Y\n";
    else cout << "N\n";
  }

  return 0;
}
