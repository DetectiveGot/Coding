#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 502, mod = 1e9+7;
ll dp[N][N], fac[N], invfac[N];

ll binpow(ll a, ll b){
	ll res=1;
	while(b){
		if(b&1) res=(res*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return res;
}

ll ncr(ll n, ll r){
	return ((fac[n]*invfac[n-r])%mod*invfac[r])%mod;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int n=s.size();
	fac[0]=invfac[0]=1;
	for(int i=1;i<=500;i++){
		fac[i]=(fac[i-1]*i)%mod;
		invfac[i]=binpow(fac[i], mod-2);
	}
	for(int i=1;i<=n;i++) dp[i+1][i]=1; //base
	//if size even -> add, else *=0 -> ex line 39
	for(int d=0;d<n;d++){
		for(int i=1;i<=n-d;i++){
			int j=i+d;
			for(int k=i+1;k<=j;k++){
				if(s[i-1]==s[k-1]){
					int tmp = (dp[i+1][k-1]*dp[k+1][j])%mod;
					tmp= (tmp*ncr((j-i+1)/2, (k-i+1)/2))%mod;
					dp[i][j]=(dp[i][j]+tmp)%mod;
				}
			}
		}
	}
	cout << dp[1][n] << endl;
	
	return 0;
}
