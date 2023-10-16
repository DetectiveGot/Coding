#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

list<string> ls;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	string s;
	for(int i=0;i<n;i++){
		cin >> s;
		ls.push_back(s);
	}
	auto it = ls.begin();
	bool ok=false;
	for(int i=0;i<2*n-1;i++){
		cin >> s;
		if(s=="SHIFT"){
			if(!ok) ok=1;
			else ++it;
		} else if(s=="RIGHT"){
			auto it2 = it;
			--it2;
			ls.erase(it2);
		}
		else if(s=="LEFT"){
			it = ls.erase(it);
			--it;
		}
	}
	cout << *it;
	
	return 0;
}
