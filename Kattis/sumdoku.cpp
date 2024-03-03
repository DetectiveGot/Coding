#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 15;
char sr[N][N], sc[N][N];
int a[N][N],a1,a2;
bool vis[N][N], row[N][N], col[N][N];

inline pii cal(char &x, char &y) {
	int l,r;
	if(x=='<' && y=='<') l=1,r=min(a1, a2)-1;
	else if(x=='<' && y=='>') l=a2+1, r=a1-1;
	else if(x=='>' && y=='<') l=a1+1, r=a2-1;
	else if(x=='>' && y=='>') l=max(a1, a2)+1, r=9;
	else if(x=='=' && y=='=' && a1==a2) l=r=a1;
	else if(x=='=' && y=='<' && a1<a2) l=r=a1;
	else if(x=='=' && y=='>' && a1>a2) l=r=a1;
	else if(y=='=' && x=='<' && a1>a2) l=r=a2;
	else if(y=='=' && x=='>' && a1<a2) l=r=a2;
	else if(x=='<' && y=='-') l=1, r=a1-1;
	else if(x=='>' && y=='-') l=a1+1, r=9;
	else if(x=='-' && y=='<') l=1, r=a2-1;
	else if(x=='-' && y=='>') l=a2+1, r=9;
	else if(x=='-' && y=='-') l=1, r=9;
	else if(x=='=' && y=='-') l=r=a1;
	else if(x=='-' && y=='=') l=r=a2;
	else r=9,l=10;
	return {l,r};
}

inline void solve(int i, int j) {
//	getch();
//	cout << "=========\n";
//	for(int r=0; r<9; r++) {
//		for(int c=0; c<9; c++) {
//			cout << a[r][c] << " ";
//		}
//		cout << "\n";
//	}
	if(j==9) ++i, j=0;
	if(i==9) {
		for(int i=0; i<9; i++) {
			for(int j=0; j<9; j++) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	a1=10-a[i-1][j],a2=10-a[i][j-1];
	pii tmp = cal(sc[i][j],sr[i][j]);
	int l=tmp.first, r=tmp.second;
//	deb(l), deb(r), deb(sr[i][j]), deb(sc[i][j]) << "\n";
	for(int d=l; d<=r; d++) {
		if(!vis[i/3*3+j/3][d] && !row[i][d] && !col[j][d]) {
			vis[i/3*3+j/3][d]=row[i][d]=col[j][d]=1;
			a[i][j]=d;
			solve(i, j+1);
			a[i][j]=0;
			vis[i/3*3+j/3][d]=row[i][d]=col[j][d]=0;
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	memset(sr, '-', sizeof(sr));
	memset(sc, '-', sizeof(sc));
	for(int i=0; i<3; i++) cin >> sr[0][i*3+1] >> sr[0][i*3+2];
	for(int i=0; i<9; i++) cin >> sc[1][i];
	for(int i=0; i<3; i++) cin >> sr[1][i*3+1] >> sr[1][i*3+2];
	for(int i=0; i<9; i++) cin >> sc[2][i];
	for(int i=0; i<3; i++) cin >> sr[2][i*3+1] >> sr[2][i*3+2];

	for(int i=0; i<3; i++) cin >> sr[3][i*3+1] >> sr[3][i*3+2];
	for(int i=0; i<9; i++) cin >> sc[4][i];
	for(int i=0; i<3; i++) cin >> sr[4][i*3+1] >> sr[4][i*3+2];
	for(int i=0; i<9; i++) cin >> sc[5][i];
	for(int i=0; i<3; i++) cin >> sr[5][i*3+1] >> sr[5][i*3+2];

	for(int i=0; i<3; i++) cin >> sr[6][i*3+1] >> sr[6][i*3+2];
	for(int i=0; i<9; i++) cin >> sc[7][i];
	for(int i=0; i<3; i++) cin >> sr[7][i*3+1] >> sr[7][i*3+2];
	for(int i=0; i<9; i++) cin >> sc[8][i];
	for(int i=0; i<3; i++) cin >> sr[8][i*3+1] >> sr[8][i*3+2];
	solve(0, 0);

	return 0;
}
