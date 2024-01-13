//credit: Khlui
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "
using namespace std;

bool palin(string s) {
	int x=s.size();
	for(int i=0; i<x/2; ++i) {
		if(s[i]!=s[x-i-1]) return 0;
	}
	return 1;
}

int main() {
	string str, s2; getline(cin, str);
	if(str.size()==0) {cout << 1; return 0;
	}
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	for(int i=0;i<str.size();i++) {
		if((str[i]>='a' and str[i]<='z') or (str[i]>='0' and str[i]<='9')) s2+=str[i];
	}
	cout << palin(s2);
	return 0;
}
