#include<bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int q; cin >> q;
	while(q--){
		int n,k,c=0; cin >> n >> k;
		string s; cin >> s;
		for(int i=0;i<n;i++)
			if(s[i]=='B') ++c, i+=k-1;
		cout << c << "\n";
	}
	
	return 0;
}
