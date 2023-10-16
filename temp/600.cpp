#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

vector<pii> v, ans;
vector<int> p;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	int x,y;
	for(int i=0;i<n;i++){
		cin >> x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end(), greater<pii>());
	for(auto &e:v){
		auto it = lower_bound(p.begin(), p.end(), e.second);
		if(it==p.end()) ans.push_back(e), p.push_back(e.second);
	}
	sort(ans.begin(), ans.end());
	for(auto &e:ans) cout << e.first << " " << e.second << "\n";
	
	return 0;
}
