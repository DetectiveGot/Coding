#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2e6+1;
int lps[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s;
	while(cin >> s && s!="."){
		int n=s.size();
		string p=s+s;
		int j=0,ans=0,m=p.size();
		lps[j]=0;
		for(int i=1;i<n;i++){
			while(j && s[i]!=s[j]) j=lps[j-1];
			if(s[i]==s[j]) ++j;
			lps[i]=j;
		}
		j=0;
		for(int i=0;i<m;i++){
			while(j && p[i]!=s[j]) j=lps[j-1];
			if(p[i]==s[j]) ++j;
			if(j==n) ++ans, j=lps[j-1];
		}
		cout << ans-1 << "\n";
	}

	return 0;
}

