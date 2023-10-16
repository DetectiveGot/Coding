#include<bits/stdc++.h>

using namespace std;

vector<string> v;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	string s;
	while(n--){
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), [&](const string &a, const string &b)->bool{
		vector<int> ca(26), cb(26);
		for(auto &e:a)
			if(e>='a' && e<='z') ca[e-'a']++;
		for(auto &e:b)
			if(e>='a' && e<='z') cb[e-'a']++;
		for(int i=0;i<26;i++){
			if(ca[i]!=cb[i]) return ca>cb;
		}
		return a<b;
	});
	for(auto &e:v) cout << e << "\n";
	
	return 0;
}
