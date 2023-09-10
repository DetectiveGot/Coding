#include<bits/stdc++.h>
#define ll unsigned long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 10001;
ll dp[N], qs[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,t; cin >> n;
	for(int i=1;i<=n;i++) cin >> qs[i], qs[i]+=qs[i-1];
	dp[1]=qs[1];
	dp[2]=qs[2];
	dp[3]=qs[3];
	for(int i=4;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=1;j<=3;j++){
			if(i-j-1>=1) dp[i]=max(dp[i], dp[i-j-1]+qs[i]-qs[i-j]);
			else dp[i]=max(dp[i], dp[1]+qs[i]-qs[2]);
		}
	}
	cout << dp[n];
	
	return 0;
} 
