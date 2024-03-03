#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 101;
bool row[N][10], col[N][10], ch[N];
int a[N][N],n,k;
vector<int> v;

inline void solve(int i, int j){
	if(j==n) ++i,j=0;
	if(i==n){
		cout << "YES\n";
		for(int r=0;r<n;r++){
			for(int c=0;c<n;c++)
				cout << a[r][c] << " ";
			cout << "\n";
		}
		exit(0);
	}
	if(a[i][j]){
		solve(i, j+1);
		return;
	}
	for(auto &e:v){
		if(!row[i][e] && !col[j][e]){
			row[i][e]=col[j][e]=1;
			a[i][j]=e;
			solve(i, j+1);
			a[i][j]=0;
			row[i][e]=col[j][e]=0;
		}
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	n,k; cin >> n >> k;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> a[i][j];
			if(!a[i][j]) continue;
			row[i][a[i][j]]=col[j][a[i][j]]=1;
			ch[a[i][j]]=1;
		}
	}
	for(int i=1;i<=n;i++) if(!ch[i]) v.push_back(i);
	solve(0, 0);
	cout << "NO";

	return 0;
}
/*
Better Time Complex Solution
https://vjudge.net/contest/481251#status//L/0/
*/
