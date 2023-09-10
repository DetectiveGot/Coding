#include<bits/stdc++.h>
#define ll unsigned long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 102;
int a[N], dp[N][N];

int main(){
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  n*=2;
  for(int i=1;i<=n;i++) cin >> a[i], dp[i][i]=a[i];
  for(int d=1;d<n;d++){
    for(int i=1;i<=n-d;i++){
      int j=i+d;
      dp[i][j]=max(dp[i+1][j-1]+a[i], dp[i+1][j-1]+a[j]);
      if(i+2<=n) dp[i][j]=max(dp[i][j], dp[i+2][j]+a[i]);
      if(j-2>=0) dp[i][j]=max(dp[i][j], dp[i][j-2]+a[j]);
    }
  }
  cout << dp[1][n];
  
  return 0;
}

/*
3
1 2 |102 103| 3 |101|
1 -> 101 103 102
2 -> 3 1 2
*/
