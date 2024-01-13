#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pdb pair<double, double>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

unordered_set<pdb> s;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	vector<pdb> v(n);
	bool _0=true,_1=true,_3=true;
	int ans=0;
	for(auto &e:v) cin >> e.first;
	for(auto &e:v) cin >> e.second;
	for(auto &e:v) s.insert(e);
	auto cal = [](double a, double b){
		return (b.second-a.second)/(b.first-a.first);	
	};
	double m=(v[1].second-v[0].second)/(v[1].first-v[0].first);
	for(int i=1;i<n;i++){
		if(v[i-1].second!=v[i].second) _0=false;
		else if(cal(v[i], v[i-1])!=m) _1=false;
		else if(!s.count(make_pair(-v[i].first, v[i].second))) _3=false;
	}
	if(_0) cout << 0;
	else if(_1) cout << 1;
	else if(_3) cout << 3;
	else if()
	
	return 0;
}
