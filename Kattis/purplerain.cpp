#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s; cin >> s;
	int n=s.size(),c=0,r=0,b=0;
	int bl=1,br=1,rl=1,rr=1,mx=0;
	pii ot;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='B') ++b, --r;
		else if(s[i-1]=='R') ++r,--b;
		if(b<0) bl=i+1,b=0;
		if(r<0) rl=i+1,r=0;
		if(r>mx) mx=r,ot={rl,i};
		if(b>mx) mx=b,ot={bl,i};
	}
	
	cout << ot.first << " " << ot.second;

	return 0;
}

