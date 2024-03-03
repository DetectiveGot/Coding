#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

set<int> s;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> v(n);
	for(auto &e:v) cin >> e;
	while(v.size()>1){
		int sz = v.size();
		vector<int> x;
		for(int i=0;i<sz;i++){
			s.insert(v[i]);
			for(int j=i+1;j<sz;j++){
				int gd = __gcd(v[i], v[j]);
				s.insert(gd);
				if(!s.count(gd)) x.push_back(gd);
			}
		}
		v=x;
	}
	for(auto &e:v) s.insert(e);
	cout << s.size();

	return 0;
}

