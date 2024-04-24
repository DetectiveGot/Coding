#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1;
int a[N];
vector<int> v;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++){
		auto it = upper_bound(v.begin(), v.end(), a[i]);
		if(it==v.end()) v.push_back(a[i]);
		else *it = a[i];
	}
	cout << n-v.size();

	return 0;
}
