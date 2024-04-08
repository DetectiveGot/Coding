#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>

using namespace std;
vector<ll> v;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll n,k,s=0,ans=0; cin >> n >> k;
  v.push_back(0);
  for(int i=0;i<n;i++){
    ll t; cin >> t;
    s+=t;
    auto it = upper_bound(v.begin(), v.end(), s-k);
    auto pos = lower_bound(v.begin(), v.end(), s);
    ans+=it-v.begin();
    v.insert(pos, s);
  }
  cout << ans;

  return 0;
}
