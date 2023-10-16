#include<bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	for(int i=0;i<3*n-3;i++){
		for(int j=0;j<2*n+1;j++){
			if((j<=n && j==i-n+3) || (j>=n && i-n==2*n-3-j) || (i>=2*n-3 && j==n)) cout << "- ";
			else if(i && i<3*n-4 && j && j<2*n && j>=n-i && j<=n+i && j-n>=i-3*n+3 && j-n<=3*n-3-i) cout << "# ";
			else cout << "- ";
		}
		cout << "\n";
	}
	
	return 0;
}
