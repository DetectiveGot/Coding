#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 501, K = 501, mod = 1e9+7;
int dp[K][N], ncr[N<<1][N<<1];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,k; cin >> n >> k;
	ncr[0][0]=1;
	for(int i=1;i<=k;i++){
		ncr[i][0]=1;
		for(int j=1;j<=i;j++){
			ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
			ncr[i][j]%=mod;
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=k;i++){
		for(int v=1;v<=v;v++){
			for(int j=1;j<=n;j++){
				for(int x=1;x<=j;x++){
					
				}
			}
		}
	}

	return 0;
}
