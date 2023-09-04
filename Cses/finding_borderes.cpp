#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e6+5, p=101, mod=1e9+7;
ll hs[N], mul[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int n=s.size();
	mul[0]=1;
	for(int i=1;i<=n;i++){
		hs[i]+=((hs[i-1]*p)%mod+s[i-1]-'a')%mod;
		mul[i]=(p*mul[i-1])%mod;
	}
	for(int i=n-1;i>=1;--i){
		if((hs[i]*mul[n-i])%mod==(hs[n]-hs[n-i]+mod)%mod){
			cout << n-i << " ";
//			cout << (hs[i]*mul[n-i])%mod << " " << (hs[n]-hs[n-i]+mod)%mod << endl;
		}
	}
	
	return 0;
}
//abcababcab

