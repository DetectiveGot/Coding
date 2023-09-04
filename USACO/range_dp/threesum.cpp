#include<bits/stdc++.h>

using namespace std;

const int N = 5002, mxV = 2e6+2, ofs = 1e6;
int a[N], dp[N][N], ch[mxV];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,q; cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int l=1;l<=n-2;l++){
		ch[a[l+1]+ofs]++;
		for(int r=l+2;r<=n;r++){
			int x=ofs-a[l]-a[r];
			if(x>=0) dp[l][r]=ch[x];
			ch[a[r]+ofs]++;
		}
		for(int j=l+1;j<=n;j++) ch[a[j]+ofs]--;
	}
	for(int d=0;d<n;d++){
		for(int i=1;i<=n-d;i++){
			int j=i+d;
			dp[i][j]+=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
		}
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		cout << dp[l][r] << "\n";
	}
	
	return 0;
} 
