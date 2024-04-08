#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << "]: " << x << " "

using namespace std;
const int N = 1e5+2;
ll fw[N], a[N], qs[N];
vector<ll> b;

void upd(int i, int val){
  for(;i<=(int)1e5;i+=i&-i) fw[i]+=val;
}

ll qry(int i){
  ll res=0;
  for(;i>=1;i-=i&-i) res+=fw[i];
  return res;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll k,ans=0,q;
  int n; cin >> n >> k;
  for(int i=1;i<=n;i++) cin >> a[i], a[i]+=a[i-1], b.push_back(a[i]);
  b.push_back(0);
  sort(b.begin(), b.end());
  int z = lower_bound(b.begin(), b.end(), 0)-b.begin()+1;
  upd(z, 1);
  for(int i=1;i<=n;i++){
    auto p = lower_bound(b.begin(), b.end(), a[i])-b.begin()+1;
    q = qry(upper_bound(b.begin(), b.end(), a[i]-k)-b.begin());
    ans+=q;
    upd(p, 1);
  }
  cout << ans;
  
  return 0;
}
