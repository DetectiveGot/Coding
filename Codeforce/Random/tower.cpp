#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+2;
vector<int> v;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,cnt=0; cin >> n;
	while(n--){
		int t; cin >> t;
		auto it=upper_bound(v.begin(), v.end(), t);
		if(it!=v.end()) *it=t;
		else v.push_back(t),cnt++;
	}
	cout << cnt;
	
	return 0;
}
