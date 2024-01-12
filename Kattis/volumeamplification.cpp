#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		ll y,t,mx=0; cin >> y;
		vector<ll> v;
		unordered_set<ll> s;
		for(int i=0;i<n;i++){
			cin >> t;
			int sz=v.size();
			for(int j=0;j<sz;j++){
				if(v[j]*t>y) continue;
				if(s.count(t*v[j])) continue;
				v.push_back(t*v[j]);
				s.insert(t*v[j]);
			}
			if(s.count(t)) continue;
			v.push_back(t);
			s.insert(t);
		}
		cout << *max_element(v.begin(), v.end()) << "\n";
	}
	
	return 0;
}
