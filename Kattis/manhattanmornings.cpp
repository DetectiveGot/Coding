#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

vector<pii> v;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	int x0,y0,xn,yn,x,y; cin >> x0 >> y0 >> xn >> yn;
	if(x0>xn) swap(x0,xn),swap(y0,yn);
	int mx=max(x0,xn), my=max(y0,yn),mnx=min(x0,xn), mny=min(y0,yn);
	for(int i=0;i<n;i++){
		cin >> x >> y;
		if(x>mx || y>my || x<mnx || y<mny) continue;
		v.emplace_back(x,y);
	}
	if(y0==yn || x0==xn){
		cout << v.size();
		return 0;
	}
	if(y0<=yn){
		vector<int> lis;
		sort(v.begin(), v.end());
		for(auto &e:v){
			auto it = upper_bound(lis.begin(), lis.end(), e.second);
			if(it==lis.end()) lis.push_back(e.second);
			else *it=e.second;
		}
		cout << lis.size();
	} else {
		vector<int> lds;
		sort(v.begin(), v.end(), [](const pii &a, const pii &b){
			if(a.first==b.first) return a.second<b.second;
			return a.first>b.first;
		});
		for(auto &e:v){
			auto it = upper_bound(lds.begin(), lds.end(), e.second);
			if(it==lds.end()) lds.push_back(e.second);
			else *it=e.second;
		}
		cout << lds.size();
	}

	return 0;
}

