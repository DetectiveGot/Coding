#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 2e5+1, K = 11;
unordered_map<ll,ll> dp[K];
struct DATA{
  ll x,y,val;
};
vector<DATA> v;

int main(){
  cin.tie(nullptr)->sync_with_stdio(0);
  ll n,k,a,b,x,y; cin >> n >> k >> a >> b;
  a%=k;
  for(int i=0;i<n;i++){
    cin >> x >> y;
    x%=k;
    if(b%y) continue;
    v.push_back({x,y,1});
    dp[x][y]=1;
  }
  for(int i=0;i<v.size();i++){
    int sz=v.size();
    for(int j=0;j<sz;j++){
      x=(v[i].x*v[j].x)%k, y=v[i].y*v[j].y;
      ll wei = v[i].val+v[j].val;
      if(y>b) continue;
      if(b%y) continue;
      if(dp[x][y]<wei){
        dp[x][y]=wei;
        v.push_back({x,y, wei});
      }
    }
  }
  cout << dp[a][b];

  return 0;
}