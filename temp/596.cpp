#include<bits/stdc++.h>

using namespace std;

const int N = 5e5+1;
int a[N];
vector<int> v;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]&1) v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	int i=0;
	for(auto &e:v){
		while(i<n && !(a[i]&1)) ++i;
		if(i<n) a[i]=e, ++i;
	}
	for(int i=0;i<n;i++) cout << a[i] << " ";
	
	return 0;
}
