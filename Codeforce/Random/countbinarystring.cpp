#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 105,mod=998244353;
int a[N][N], dp[N][N],n;

bool check(int x, int y){
	for(int i=1;i<=n;i++){
		if(a[i][x]==1 && i<=y) return false;
		else if(a[i][x]==2 && i>y) return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cin >> a[i][j];
		}
	}
	if(a[1][1]!=2) dp[1][0]=2;
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			if(check(i+1,j)) (dp[i+1][j]+=dp[i][j])%=mod;
			if(check(i+1,i)) (dp[i+1][i]+=dp[i][j])%=mod;
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++) (cnt+=dp[n][i])%=mod;
	cout << cnt;
	
	return 0;
}
