#include<bits/stdc++.h>
#define ll long long
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const string tar = "OTOG";

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s; cin >> s;
	int n=s.size();
	int i=0,ans=0,ans2=0;
	while(i<n){
		int c=0;
		for(int j=0;j<4;j++){
			if(tar[j]==s[i]) ++i,++c;
		}
		ans+=4-c;
		++ans2;
	}
	cout << ans << " " << ans2;
	
	return 0;
}
