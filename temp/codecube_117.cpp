#include<bits/stdc++.h>

using namespace std;

const int N = 1001, K = 100007;
bool dp[2][K];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int q,cs=0; cin >> q;
	while(q--){
		int n,k,t,ans=0; cin >> n >> k;
		int nw=0, pv=1;
		memset(dp, 0, sizeof(dp));
		for(int i=1;i<=n;i++){
			nw^=1, pv^=1;
			cin >> t;
			dp[nw][t%k]=1;
			for(int j=0;j<k;j++){
				dp[nw][(j+t)%k]|=dp[pv][(j+t)%k];
				dp[nw][(j+t)%k]|=dp[pv][j];
			}
			memset(dp[pv], 0, sizeof(dp[pv]));
		}
		for(int i=k-1;i>=0;--i){
			if(dp[nw][i]){
				ans=i;
				break;
			}
		}
		cout << "Case #" << ++cs << ": " << ans << "\n";
	}
	
	return 0;
}
/*
1
4 18
1 2 3 4
*/
