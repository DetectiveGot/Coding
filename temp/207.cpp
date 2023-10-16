#include<bits/stdc++.h>

using namespace std;

const int N = 1001;
int qs[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,q,l,r; cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> qs[i], qs[i]+=qs[i-1];
	while(q--){
		cin >> l >> r;
		cout << qs[r]-qs[l-1] << "\n";
	}
	
	return 0;
}
