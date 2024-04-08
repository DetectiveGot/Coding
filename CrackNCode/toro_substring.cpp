#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;
const int N = 1e5+2;
vector<ll> v;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll n,cnt=0,ans=0; cin >> n;
  string s; cin >> s;
  v.push_back(0);
  for(int i=0;i<n;i++){
    if(s[i]=='A') cnt++;
    else cnt--;
    auto it = upper_bound(v.begin(), v.end(), cnt-1);
    auto pos = lower_bound(v.begin(), v.end(), cnt);
    ans+=it-v.begin();
    v.insert(pos, cnt);
  }
  cout << ans;

  return 0;
}
