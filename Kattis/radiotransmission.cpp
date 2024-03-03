#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "
 
using namespace std;
 
const int N = 1e6+1;
int lps[N];
 
int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	string s; cin >> s;
	int j=0;
	for(int i=1;i<n;i++){
		while(j && s[i]!=s[j]) j=lps[j-1];
		if(s[i]==s[j]) ++j;
		lps[i]=j;
	}
	cout << n-lps[n-1];
	
	return 0;
}

