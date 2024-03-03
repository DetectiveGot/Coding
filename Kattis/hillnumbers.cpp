#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 20;
int dp[N][10][2];
//0->already smaller

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s; cin >> s;
	int n=s.size();
	s="."+s;
	int last = s[n]-'0';
	for(int i=0;i<=9;i++) dp[1][i][1]=1;
	for(int i=1;i<=n;i++){
		int d=s[i]-'0';
		for(int j=0;j<=9;j++){ //now
			for(int k=0;k<=9;k++){ //next
				dp[i+1][k][0]+=dp[i][j][0];
				if(j<d){
					dp[i+1][k][0]+=dp[i][j][1];
				} else if(j==d){
					dp[i+1][k][1]+=dp[i][j][1];
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=9;i++){
		deb(i) << dp[n][i][0] << " " << dp[n][i][1] << "\n";
	}
	cout << ans;
	
	return 0;
}
