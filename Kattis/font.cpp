#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 26;
int a[N],dp[1<<N|1],n;

inline ll dfs(int i, int b){
	if(i==n) return b==(1<<N)-1;
	if(dp[b]) return dp[b];
	return dfs(i+1, b)+dfs(i+1, b|a[i]);
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> n;
	string s;
	for(int i=0;i<n;i++){
		cin >> s;
		for(auto &e:s) a[i]|=1<<e-'a';
	}
	cout << dfs(0, 0);
	
	return 0;
}
