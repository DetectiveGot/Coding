#include<bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	for(int i=1;i<=2*n-1;i++){
		for(int j=1;j<=n*4+3;j++){
			if(j==1 || j==n+2 || j==2*n+1 || j==3*n+3) cout << "#";
			else if((i==1 || i==n) && (j<=n || (j>=2*n+3 && j<=3*n+2 && i<=n))) cout << "#";
			else cout << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
