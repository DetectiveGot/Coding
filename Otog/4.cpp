#include<bits/stdc++.h>
#define ll unsigned long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e4+1, mod = 1e9+7;
ll a[N], fac[N], inv[N];

inline ll bp(ll a, ll b){
  ll res=1;
  while(b){
    if(b&1) res=res*a%mod;
    a=a*a%mod;
    b>>=1;
  }
  return res;
}

inline ll ncr(ll n, ll r){
  return fac[n]*inv[n-r]%mod*inv[r]%mod;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(0);
  int n,k; cin >> n >> k;
  ll ans=0;
  fac[0]=inv[0]=1;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    fac[i]=fac[i-1]*i%mod;
    inv[i]=bp(fac[i], mod-2);
  }
  sort(a+1, a+n+1);
  for(int i=k;i<=n;i++){
    ans+=ncr(i-1, k-1)*a[i]%mod;
    ans%=mod;
  }
  cout << ans;

  return 0;
}
