#include<bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const int N = 5002, mxN = 1e6+2, mod = 1e9+7;
ll dp[N];
string a[mxN];
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int n, siz=s.size(); cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	dp[0]=1;
	for(int i=1;i<=siz;i++){
		for(int j=1;j<=n;j++){
			int sz=a[j].size();
			if(i-sz<0) continue;
			bool ok=true;
			for(int k=1;k<=sz;k++){
				if(s[i-sz+k-1]!=a[j][k-1]){
					ok=false;
					break;
				}
			}
			if(ok) dp[i]=(dp[i]+dp[i-sz])%mod;
		}
	}
	cout << dp[siz] << "\n";
	
	return 0;
}
/*
ababc
4
ab
abab
c
cb
*/
