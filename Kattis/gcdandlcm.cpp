#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1;
vector<pii> v;

 int main(){
   cin.tie(nullptr)->sync_with_stdio(0);
   ll x,y; cin >> x >> y;
   ll lm = y/x, sq=sqrt(lm);
   for(ll i=1;i<=sq;i++){
     if(lm%i==0){
       if(__gcd(lm/i, i)==1){
       	cout << i*x << " " << lm/i*x << "\n";
       	if(i!=lm/i) v.push_back({lm/i*x, i*x});
	   }
     }
   }
   reverse(v.begin(), v.end());
   for(auto &e:v) cout << e.first << " " << e.second << "\n";

   return 0;
 }
