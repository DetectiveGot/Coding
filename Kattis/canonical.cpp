#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 101, mxN = 2e6+1;
int a[N], dp[mxN], gd[mxN];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	dp[0]=0;
	int pt=0;
	for(int i=1;i<mxN;i++){
		while(pt<n && a[pt+1]<=i) ++pt;
		dp[i]=1e9;
		gd[i]=gd[i-a[pt]]+1;
		for(int j=1;j<=n && i-a[j]>=0;j++)
			dp[i]=min(dp[i], dp[i-a[j]]+1);
		if(gd[i]>dp[i]){
			cout << "non-canonical";
			return 0;
		}
	}
	cout << "canonical";

	return 0;
}

