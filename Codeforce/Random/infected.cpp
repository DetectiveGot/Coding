#include<bits/stdc++.h>

using namespace std;

const int N = 102;
int dp[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int n; cin >> n;
	while(n--){
		string a; cin >> a;
		for(int i=1;i<=s.size();i++){
			for(int j=1;j<=a.size();j++){
				if(s[i-1]==a[j-1]) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
		cout << dp[s.size()][a.size()] << "\n";
		memset(dp,0,sizeof(dp));
	}
	
	return 0;
}
