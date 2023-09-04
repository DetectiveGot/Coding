#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int n=s.size(), cnt=0;
		vector<bool> v(26);
		for(char& e:s){
			if(v[e-'a']){
				cnt+=2;
				v[e-'a']=false;
				for(int i=0;i<26;i++) v[i]=0;
			} else v[e-'a']=true;
		}
		cout << n-cnt << "\n";
	}
	
	return 0;
}
