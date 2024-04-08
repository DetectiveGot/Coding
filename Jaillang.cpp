#include<bits/stdc++.h>

using namespace std;

const int N = 502;
int rt[N][N], down[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int r,c; cin >> r >> c;
	string s;
	for(int i=1;i<=r;i++){
		cin >> s;
		for(int j=1;j<=c;j++){
			if(s[j-1]=='.'){
				rt[i][j]++, down[i][j]++;
				rt[i][j]+=rt[i][j-1];
				down[i][j]+=down[i-1][j];
			}
			
		}
	}
	int mx=0;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			int k=rt[i][j];
			while(k>=3){
				if(j-k+1>=1 && i+2*(k-1)<=r){
					if(down[i+k-1][j-k+1]>=k && rt[i+k-1][j]>=k && rt[i+2*(k-1)][j]>=k && down[i+2*(k-1)][j]>=k){
						mx=max(mx, k);
						break;
					}
				}
				k--;
			}
		}
	}
	if(mx>=3) cout << mx;
	else cout << 0;
	
	return 0;
}
