#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1;

 int main(){
   cin.tie(nullptr)->sync_with_stdio(0);
   ll a,b; cin >> a >> b;
   if(a&1) cout << 0;
  else {
    ll res=1, mul = a>>1;
    for(int i=1;i<=b;i++) res*=mul, res%=a;
    cout << res;
  }
   
   return 0;
 }
