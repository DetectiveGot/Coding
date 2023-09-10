#include<bits/stdc++.h>

using namespace std;

string s;

void flip(int l, int r){
	if(l==r) return;
	int mid = (l+r)/2;
	flip(l, mid);
	flip(mid+1, r);
	reverse(s.begin()+l, s.begin()+r+1);
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	cin >> s;
	flip(0,n-1);
	cout << s;
	
	return 0;
}
