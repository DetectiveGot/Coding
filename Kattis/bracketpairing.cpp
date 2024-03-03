#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 22, mod = 1e9+7;
int dp[N][N];

inline int match(char &a, char &b){
	int cnt=0;
	if((a=='?' || a=='(') && (b=='?' || b==')')) ++cnt;
	if((a=='?' || a=='[') && (b=='?' || b==']')) ++cnt;
	if((a=='?' || a=='{') && (b=='?' || b=='}')) ++cnt;
	if((a=='?' || a=='<') && (b=='?' || b=='>')) ++cnt;
	return cnt;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s; cin >> s;
	int n=s.size();
	s="."+s;
	for(int i=1;i<=n;i++) dp[i-1][i]=match(s[i-1], s[i]);
	for(int d=1;d<n;d++){
		for(int i=1;i<=n-d;i++){
			int j=i+d;
			for(int k=i+1;k<j;k+=2){
				dp[i][j]+=dp[i][k]*dp[k+1][j]%mod*match(s[i], s[k])%mod;
				dp[i][j]%=mod;
			}
		}
	}
	cout << dp[1][n] << "\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

