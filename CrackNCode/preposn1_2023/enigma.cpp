#include<bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2e5+1, mod = 26;
int a[N], x[mod];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s; cin >> s;
	int n=s.size(),ans=0;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<26;i++){
		for(int j=0;j<n;j++){
			int t=i*a[j]%mod;
			t+=(s[j]-'A');
			t%=mod;
			x[t]++;
		}
		for(int j=0;j<26;j++){
			ans=max(ans, x[j]);
			x[j]=0;
		}
	}
	cout << ans;
	
	return 0;
}