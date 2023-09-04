#include<bits/stdc++.h>

using namespace std;

const int N = 250;
int a[N], dp[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("248_in.txt", "r", stdin);
	freopen("248_out.txt", "w", stdout);
	int n,mx=0; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i], dp[i][i]=a[i],mx=max(mx, a[i]);
	for(int d=1;d<n;d++){
		for(int i=1;i<=n-d;i++){
			int j=i+d;
			for(int k=i;k<j;k++){
				if(dp[i][k]==dp[k+1][j]) dp[i][j]=max(dp[i][j], dp[i][k]+1);
			}
			mx=max(mx, dp[i][j]);
		}
	}
	cout << mx;
	
	return 0;
}
