#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5001;
bool dp[N][N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s; cin >> s;
	int n=s.size();
	string a,b; cin >> a >> b;
	int sa=a.size(), sb=b.size();
	dp[0][0]=1;
	for(int i=1;i<=sa;i++) if(a[i-1]==s[i-1]) dp[i][0]|=dp[i-1][0];
	for(int i=1;i<=sb;i++) if(b[i-1]==s[i-1]) dp[0][i]|=dp[0][i-1];
	for(int i=1;i<=sa;i++){
		for(int j=1;j<=sb;j++){
			if(a[i-1]==s[i+j-1]) dp[i][j]|=dp[i-1][j];
			if(b[j-1]==s[i+j-1]) dp[i][j]|=dp[i][j-1];
		}
	}
	if(dp[sa][sb]) cout << "yes";
	else cout << "no";
	
	return 0;
}
