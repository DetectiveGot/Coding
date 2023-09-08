#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 501;
ll dp[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;--j){
			dp[j]+=dp[j-i];
		}
	}
	cout << dp[n]-1;
	
	return 0;
}
