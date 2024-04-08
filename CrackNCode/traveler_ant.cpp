#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int mxN = 5, mxM = 62, mod = 1e9+7;
ll ans[mxN][mxN], tmp[mxN][mxN], pw[mxM][mxN][mxN];
/*
0->down
1->down long
2->up
3->up long
*/
inline ll solve(ll n){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(i==j) ans[i][j]=1;
			else ans[i][j]=0;
		}
	}
	int p=0;
	while(n){
		if(n&1){
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					tmp[i][j]=0;
					for(int k=0;k<4;k++){
						tmp[i][j]+=ans[i][k]*pw[p][k][j]%mod;
						tmp[i][j]%=mod;
					}
				}
			}
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					ans[i][j]=tmp[i][j];
				}
			}
		}
		++p;
		n>>=1;
	}

	return (ans[2][1]*2%mod+ans[2][2]+ans[3][1]*2%mod+ans[3][2])%mod;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int q; cin >> q;
	pw[0][0][3]=1;
	pw[0][1][0]=2;
	pw[0][1][1]=1;
	pw[0][2][1]=1;
	pw[0][3][2]=2;
	pw[0][3][3]=1;
	for(int p=1;p<=60;p++){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				tmp[i][j]=0;
				for(int k=0;k<4;k++){
					tmp[i][j]+=pw[p-1][i][k]*pw[p-1][k][j]%mod;
					tmp[i][j]%=mod;
				}
			}
		}
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				pw[p][i][j]=tmp[i][j];
	}
	ll n;
	while(q--){
		cin >> n;
		cout << solve(n-1) << "\n";
	}
	
	return 0;
}
