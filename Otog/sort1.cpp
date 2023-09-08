#include<bits/stdc++.h>

using namespace std;

int cmp(const void *l, const void *r){
	return *(int*)l -  *(int*)r;
}
int cmp2(const void *l, const void *r){
	return *(int*)r - *(int*)l;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,op; cin >> n >> op;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	if(!op) sort(v.begin(), v.end());
	else sort(v.begin(), v.end(), greater<int>());
	for(auto&e:v) cout << e << " ";
	
	return 0;
}
