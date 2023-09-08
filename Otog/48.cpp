#include<bits/stdc++.h>

using namespace std;

vector<string> v;

bool cmp(const string &a, const string &b){
	return a+b<b+a;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	string s;
	for(int i=0;i<n;i++){
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	for(auto&e:v) cout << e;
	
	return 0;
}
/*
5
1 1112 1003 583 15 100
100 1003 1 1112 15 583
*/
