#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5+2;

void solve(){
	vector<int> v;
	int n,t; cin >> n;
	ll s=0,cnt=0;
	for(int i=1;i<=n;i++){
		cin >> t;
		v.push_back(t);
		s+=t;
	}
	s<<=1;
	if(s%n){
		cout << "0\n";
		return;
	}
	s/=n;
	sort(v.begin(), v.end());
	for(int i=0;i<v.size();i++){
		if(s-v[i]<0) break;
		cnt+=upper_bound(v.begin()+i+1, v.end(), s-v[i])-lower_bound(v.begin()+i+1, v.end(), s-v[i]);
	}
	cout << cnt << "\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}
