#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int q; cin >> q;
	while(q--){
		string s; cin >> s;
		int cnt=1;
		if(s[0]=='?') cnt=9;
		for(int i=1;i<s.size();i++){
			if(s[i]=='?') cnt*=10;
		}
		cout << (s[0]=='0'?0:cnt) << "\n";
	}
	
	return 0;
}
