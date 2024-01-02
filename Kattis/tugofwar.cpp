#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ":" << x << "] "

using namespace std;

const int N = 100, mxN = 22501;
int a[N];
bool dp[51][mxN];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,s=0; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i],s+=a[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=n>>1;j>=1;--j)
			for(int k=s;k>=a[i];--k)
				dp[j][k]|=dp[j-1][k-a[i]];
	int mn=INT_MAX,r1=0,r2=s;
	for(int j=s;j>=0;--j)
		if(dp[n>>1][j] && abs(2*j-s)<mn) mn=2*j-s, r1=min(j,s-j), r2=max(j, s-j);
	cout << r1 << " " << r2;
	
	return 0;
}
