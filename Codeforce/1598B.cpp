#include<bits/stdc++.h>

using namespace std;

const int N = 1002;
bool a[N][6];
int n;

bool check(const int &x, const int &y){
	int c1=0,c2=0,c3=0;
	for(int i=1;i<=n;i++){
		if(a[i][x]&a[i][y]) c3++;
		else if(a[i][x]) c1++;
		else if(a[i][y]) c2++;
	}
	return c1<=n/2 & c2<=n/2 & c1+c2+c3==n;
}

void solve(){
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=5;i++){
		for(int j=i+1;j<=5;j++){
			if(check(i,j)){
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}
