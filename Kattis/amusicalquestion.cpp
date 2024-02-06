#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1001;
int a[N];
bool dp[N][N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int c,n; cin >> c >> n;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		for(int j=c;j>=0;--j){
			for(int k=c;k>=0;--k){
				if(j-a[i]>=0) dp[j][k]|=dp[j-a[i]][k];
				if(k-a[i]>=0) dp[j][k]|=dp[j][k-a[i]];
			}
		}
		
	}
	pii ans;
	int mn=1e9,mx=0;
	for(int i=0;i<=c;i++){
		for(int j=0;j<=c;j++){
			if(i==0 && j==0) continue;
			if(dp[i][j]){
				if(mx<i+j) mx=i+j, ans={max(i,j),min(i,j)}, mn=abs(i-j);
				else if(mx==i+j && abs(i-j)<mn) mx=i+j,mn=abs(i-j), ans={max(i,j),min(i,j)};
			}
		}
	}
	cout << ans.first << " " << ans.second;

	return 0;
}

