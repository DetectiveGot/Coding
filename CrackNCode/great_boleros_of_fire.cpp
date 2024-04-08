#include<bits/stdc++.h>

using namespace std;

const int mxN = 1e5+2;
int qs[8][mxN], a[mxN];

bool check(int &l, int &r){
	for(int i=0;i<7;i++)
		if(qs[i][r]-qs[i][l]<a[i+1]) return false;
	return true;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,s=0; cin >> n;
	for(int i=1;i<=n;i++){
		char c; cin >> c;
		qs[c-'a'][i]++;
		for(int j=0;j<7;j++){
			qs[j][i]+=qs[j][i-1];
		}
	}
	for(int i=1;i<=n;i++) cin >> a[i], s+=a[i];
	int r=1, ans=INT_MAX;
//	for(int i=0;i<7;i++){
//		cout << (char)(i+'a') << ": ";
//		for(int j=1;j<=n;j++) cout << qs[i][j] << " ";
//		cout << "\n";
//	}
	for(int i=0;i<n;i++){
		while(r<n && !check(i, r)) ++r;
		if(check(i, r)){
			ans=min(ans, r-i-s);
		}
	}
	cout << ans;
	
	return 0;
}
