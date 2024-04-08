#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>

using namespace std;
vector<ll> v[100];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll n,k,s=0,ans=0,t; cin >> n >> k;
  ll m=50;
  v[m].push_back(0);
  ll mn=100;
  for(int i=0;i<n;i++){
    int g1=1; cin >> t;
    s+=t;
    if(s-k==0) g1=m;
    else if(s-k>0){
      g1=m+(ll)log10(s-k);
    }
    else g1=m-(ll)log10(-s+k);
    
    if(mn>g1) mn=g1;
    auto it = upper_bound(v[g1].begin(), v[g1].end(), s-k);
    ans+=it-v[g1].begin();
    for(int i=mn;i<g1;i++){
      ans+=v[i].size();
    }
    if(s==0) g1=m;
    else if(s>0){
      g1=m+(ll)log10(s);
    }
    else g1=m-(ll)log10(-s);
    auto pos = lower_bound(v[g1].begin(), v[g1].end(), s);
    v[g1].insert(pos, s);
  }
  cout << ans;

  return 0;
}
