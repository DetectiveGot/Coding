#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2001;
int dp[N][N], qs[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,k; cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> qs[i];
		qs[i]+=qs[i-1];
		dp[1][i]=qs[i];
	}
	for(int i=2;i<=k;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e9;
			for(int l=i;l<=j;l++){
				dp[i][j]=min(dp[i][j], dp[i-1][l-1]|(qs[j]-qs[l-1]));
			}
		}
	}
//	cout << dp[k][n] << "\n";
//	for(int i=1;i<=k;i++){
//		for(int j=1;j<=n;j++){
//			if(dp[i][j]==1e9) cout << "- ";
//			else cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << "----\n";
//	for(int i=1;i<=n;i++) cout << qs[i] << " ";
	
	return 0;
}
