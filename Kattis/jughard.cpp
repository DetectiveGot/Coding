#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc; cin >> tc;
	while(tc--){
		int a,b,d; cin >> a >> b >> d;
		if(d%__gcd(a,b)==0) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}

