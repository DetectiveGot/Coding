#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+2, K = 32;
int dp[N][K];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,q; cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> dp[i][0];
	}
	for(int j=1;j<=30;j++){
		for(int i=1;i<=n;i++){
			dp[i][j]=dp[dp[i][j-1]][j-1];
		}
	}
	while(q--){
		int x,k; cin >> x >> k;
		for(int i=0;i<=30 && (1<<i)<=k;i++){
			if(k&(1<<i)){
				x=dp[x][i];
			}
		}
		cout << x << "\n";
	}
	
	return 0;
}
