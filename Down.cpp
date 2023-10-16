#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2001;
char a[N][N];
int n,w,l,k; 

inline void draw(int x, int y){
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			if(abs(n-i)+abs(n-j)<=n) a[i+x][j+y]='#';
		}
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> n >> w >> l;
	k=2*n+1;
	memset(a,'.',sizeof(a));
	for(int i=0;i<w/n+1;i++){
		for(int j=0;j<w/n+1;j++){
			draw(i*k+j, i+j*k);
		}
	}
	for(int i=k+1;i<(l+2)*k+1;i++){
		for(int j=k+1;j<=w+k;j++){
			cout << a[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}
