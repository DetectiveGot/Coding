#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;
const int N = 5;
const ll mod = 1e9+7;
ll a[N][N], tmp[N][N], ans[N][N];

inline void solve(int n, ll pw){
  while(pw){
    if(pw&1){
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          tmp[i][j]=0;
          for(int k=1;k<=n;k++){
            tmp[i][j]=(tmp[i][j]+ans[i][k]*a[k][j]%mod)%mod;
            tmp[i][j]%=mod;
          }
        }
      }
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          ans[i][j]=tmp[i][j];
        }
      }
    }
    pw>>=1;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        tmp[i][j]=0;
        for(int k=1;k<=n;k++){
          tmp[i][j]=(tmp[i][j]+a[i][k]*a[k][j]%mod)%mod;
        }
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        a[i][j]=tmp[i][j];
      }
    }
  }
  cout << ans[1][1];
//  for(int i=1;i<=n;i++){
//  	for(int j=1;j<=n;j++){
//  		cout << a[i][j] << " ";
//	  }
//	  cout << endl;
//  }
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(0);
  ll n; cin >> n;
  a[1][2]=a[2][3]=a[2][4]=a[4][3]=a[3][2]=a[3][1]=1;
  for(int i=1;i<=4;i++) ans[i][i]=1;
  solve(4, n);

  return 0;
}
