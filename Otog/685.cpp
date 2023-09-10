#include<bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	double r=n/2,rg;
	for(double i=0;i<n;i++){
		for(double j=0;j<n;j++){
			rg=abs((r-i)*(r-i)+(r-j)*(r-j)-r*r);
			if(rg<=r) cout << "#";
			else cout << "-";
		}
		cout << "\n";
	}
	
	return 0;
}
