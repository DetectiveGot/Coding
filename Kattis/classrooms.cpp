#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

multiset<int> ms;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,k,ans=0; cin >> n >> k;
	vector<pii> v(n);
	for(auto &e:v) cin >> e.second >> e.first;
	sort(v.begin(), v.end());
	for(auto &e:v){
		auto it = ms.lower_bound(e.second);
		if(it!=ms.begin()){
			--it;
			ms.erase(it);
			ms.insert(e.first);
			++ans;
		} else if(ms.size()<k) ms.insert(e.first), ++ans;
	}
	cout << ans;

	return 0;
}

