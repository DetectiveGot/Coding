#include<bits/stdc++.h>

using namespace std;

const int N = 5002;
int dp[N][N];
bool p[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int q,l,r,n=s.size(); cin >> q;
	for(int d=1;d<n;d++){
		for(int i=1;i<=n-d;i++){
			int j=i+d;
			if(i==j){
				dp[i][i]=1;
				p[i][i]=1;
				continue;
			}
			p[i][j]=p[i+1][j-1] & s[i-1]==s[j-1];
			dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+p[i][j];
		}
	}
	while(q--){
		cin >> l >> r;
		cout << dp[l][r] << "\n";
	}
	
	return 0;
}
