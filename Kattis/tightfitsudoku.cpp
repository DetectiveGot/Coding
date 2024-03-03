#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 15, n=6;
bool row[N][N], col[N][N], group[N][N];
string a[N][N];

//i/3*3+j/3
//i/2*2+j/3
/*
0 0
(2, 0) -> 3
*/

inline void solve(int i, int j) {
	if(j==n) {
		i=i+1,j=0;
	}
	if(i==n) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	if(a[i][j].size()==1) {
		if(a[i][j]=="-") {
			for(int d=1; d<=9; d++) {
				if(row[i][d] || col[j][d] || group[i/2*2+j/3][d]) continue;
				a[i][j]=char('0'+d);
				row[i][d]=col[j][d]=group[i/2*2+j/3][d]=1;
				solve(i, j+1);
				a[i][j]='-';
				row[i][d]=col[j][d]=group[i/2*2+j/3][d]=0;
			}
			return;
		} else {
			solve(i, j+1);
			return;
		}
	} else {
		if(a[i][j]=="-/-") {
			for(int d=1; d<=9; d++) {
				for(int k=d+1; k<=9; k++) {
					if(row[i][d] || col[j][d] || group[i/2*2+j/3][d]) continue;
					if(row[i][k] || col[j][k] || group[i/2*2+j/3][k]) continue;
					a[i][j][0]=char('0'+d);
					a[i][j][2]=char('0'+k);
					row[i][d]=col[j][d]=group[i/2*2+j/3][d]=1;
					row[i][k]=col[j][k]=group[i/2*2+j/3][k]=1;
					solve(i, j+1);
					a[i][j][0]='-';
					a[i][j][2]='-';
					row[i][d]=col[j][d]=group[i/2*2+j/3][d]=0;
					row[i][k]=col[j][k]=group[i/2*2+j/3][k]=0;
				}
			}
		} else if(a[i][j][0]=='-') {
			for(int d=1; d<a[i][j][2]-'0'; d++) {
				if(row[i][d] || col[j][d] || group[i/2*2+j/3][d]) continue;
				a[i][j][0]=char('0'+d);
				row[i][d]=col[j][d]=group[i/2*2+j/3][d]=1;
				solve(i, j+1);
				a[i][j][0]='-';
				row[i][d]=col[j][d]=group[i/2*2+j/3][d]=0;
			}
		} else {
			for(int d=a[i][j][0]-'0'+1; d<=9; d++) {
				if(row[i][d] || col[j][d] || group[i/2*2+j/3][d]) continue;
				a[i][j][2]=char('0'+d);
				row[i][d]=col[j][d]=group[i/2*2+j/3][d]=1;
				solve(i, j+1);
				a[i][j][2]='-';
				row[i][d]=col[j][d]=group[i/2*2+j/3][d]=0;
			}
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	for(int i=0; i<6; i++) {
		for(int j=0; j<6; j++) {
			cin >> a[i][j];
			for(auto &e:a[i][j]) {
				if(e=='-' || e=='/') continue;
				row[i][e-'0']=col[j][e-'0']=group[i/2*2+j/3][e-'0']=1;
			}

		}
	}
	solve(0, 0);

	return 0;
}
