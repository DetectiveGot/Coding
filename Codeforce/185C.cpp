#include<bits/stdc++.h>

using namespace std;

const int N = 52;
int a[N], w[N][N];
struct DATA{
	int l,r,lr;
} dp[N][N];
//https://codeforces.com/problemset/problem/185/C
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i], dp[1][i]={a[i], a[i], a[i]};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			cin >> w[i][j];
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(dp[i-1][j].l>=w[i-1][j]) dp[i][j].l+=dp[i-1][j].l;
			if(dp[i-1][j+1].r>=w[i-1][j+1]) dp[i][j].r+=dp[i-1][j+1].r;
			if(dp[i-1][j].lr>=w[i-1][j]) dp[i][j].lr+=dp[i-1][j].lr;
			if(dp[i][j+1].r>=w[i][j+1]) dp[i][j].lr+=dp[i][j+1].r;
		}
	}
	if(dp[n][1].l>=w[n][1] || dp[n][1].r>=w[n][1] || dp[n][1].lr>=w[n][1]) cout << "Cerealguy";
	else cout << "Fat Rat";
	
	return 0;
}
