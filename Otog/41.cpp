#include<bits/stdc++.h>

using namespace std;

const int N = 3e5+1;
int a[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int q,n; cin >> q;
	while(q--){
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		int cnt=n;
		for(int i=n;i>=1;--i){
			if(a[i]==cnt) --cnt;
		}
		cout << cnt << "\n";
	}
	
	return 0;
}
/*
5
1 5 3 4 2
*/
