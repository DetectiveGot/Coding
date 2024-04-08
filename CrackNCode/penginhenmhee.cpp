#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

vector<pii> v;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,l,r; cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> l >> r;
		v.push_back({l,r});
	}
	cout << n;

	return 0;
}

