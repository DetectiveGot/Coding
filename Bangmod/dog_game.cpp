#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 101, K = 5001;
int dp[500001];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	int s=0,m,d;
	for(int i=0;i<n;i++){
		cin >> m >> d;
		s+=m;
		for(int j=s;j>=m;--j) dp[j]=max(dp[j], dp[j-m]+d);
	}
	int mn; cin >> mn;
	int ans=0;
	for(int j=mn;j>=0;--j) ans=max(ans, dp[j]);
	cout << ans;
	
	return 0;
}
