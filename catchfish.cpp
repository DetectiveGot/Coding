#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+2;
ll qs[N];
vector<pii> v;
deque<int> dq;

int main(){
  cin.tie(nullptr)->sync_with_stdio(0);
  ll n,m,l,u,p,x; cin >> n >> m >> l >> u;
  v.push_back({0,0});
  for(int i=0;i<m;i++){
    cin >> p >> x;
    v.push_back({p,x});
    v.push_back({min(p+2*u, n), 0});
  }
  sort(v.begin(), v.end());
  m<<=1;
  int pt = 0;
  ll ans=0;
  for(int i=1;i<=m;i++){
    qs[i]=qs[i-1]+v[i].second;
    while(!dq.empty() && v[i].first-v[dq.front()].first>2*u+1){
      ++pt;
      while(!dq.empty() && dq.front()<pt) dq.pop_front();
    }
    while(!dq.empty() && qs[dq.back()]>qs[pt]) dq.pop_back();
    if(v[i].first-v[pt].first>2*l+1) dq.push_back(pt);
    if(!dq.empty()) ans=max(ans, qs[i]-qs[dq.front()]);
  }
  cout << ans;

  return 0;
}
/*
18 5 2 4
2 1
8 2
14 -2
16 -1
18 6

12 6 0 1
2 -1
4 3
6 -2
8 5
10 3
12 2

10 10 3 4
1 58 
2 36 
3 81 
4 -7
5 46
6 49
7 87
8 -58
9 98
10 -15

*/
