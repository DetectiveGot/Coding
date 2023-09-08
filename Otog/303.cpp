#include<bits/stdc++.h>

using namespace std;

const int N = 101;
int dp[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,ans=0; cin >> n;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[j]+=dp[j-i];
		}
	}
	cout << dp[n];
	
	return 0;
}
