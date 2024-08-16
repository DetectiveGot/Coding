#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,c=0; cin >> n;
	ll s=0;
	bool t;
	while(n--){
		cin >> t;
		if(t) c++;
		else s+=c;
	}
	cout << s;
	
	return 0;
}