#include<bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int h,m; cin >> h >> m;
	m-=45;
	if(m<0){
		if(h-1>=0) cout << h-1 << " ";
		else cout << "23 ";
	} else cout << h << " ";
	cout << (m+60)%60;
	
	return 0;
}
