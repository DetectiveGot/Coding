#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1;
ll qs[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,q,t,l,r; cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> t;
		qs[i]+=t;
		qs[i]+=qs[i-1];
	}
	while(q--){
		cin >> l >> r;
		cout << qs[r]-qs[l-1] << "\n";
	}
	
	return 0;
}
