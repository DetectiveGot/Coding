#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	vector<pair<double, string>> v(n);
	for(auto &e:v) cin >> e.first >> e.second;
	sort(v.begin(), v.end(), greater<pair<double,string>>());
	for(int i=0;i<min(3, (int)v.size());i++) cout << v[i].second << "\n";
	
	return 0;
}
