#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pdb pair<double, double>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	vector<pdb> v(n);
	for(auto &e:v) cin >> e.first;
	for(auto &e:v) cin >> e.second;
	double d=log10(v[0].second)/log10(v[1].first);
	cout << floor(d);
	
	return 0;
}
/*
20
35 40 20 30 25 15 85 10 70 50 90 5 75 80 55 60 0 95 45 65
216.32 245.12 161.14 184.22 171.5 99.43 430.55 68.0 350.79 253.92 445.55 80.83 365.9 389.95 270.78 315.44 31.02 502.06 235.17 326.09
*/
