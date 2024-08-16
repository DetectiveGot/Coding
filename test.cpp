#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

inline void solve(){
	int a,b,c,d; cin >> a >> b >> c >> d;
	--a,--b,--c,--d;
	vector<int> ch(12);
	ch[a]=ch[b]=1;
	ch[c]=ch[d]=2;
	int pv = -1;
	for(int i=0;i<12;i++){
		if(pv==ch[i]) return void(cout << "NO\n");
		if(ch[i]) pv = ch[i];
	}
	cout << "YES\n";
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc; cin >> tc;
	while(tc--) solve();

	return 0;
}
