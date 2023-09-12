#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1005;
ll dp[N][N],n,m;
char a[N][N];

inline ll cal(int x1, int y1, int x2, int y2){
	return dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1];
}

inline void play(int x1, int y1, int x2, int y2){
	if(x1==x2 && y1==y2) return void(cout << a[x1][y1]);
	ll t = cal(x1,y1,x2,y2), area = (x2-x1+1)*(y2-y1+1);
	if(t==0) return void(cout << 0);
	else if(t==area) return void(cout << 1);
	int mx=(x1+x2)/2,my=(y1+y2)/2;
	cout << "D";
	play(x1, y1, mx, my);
	if(my+1<=y2) play(x1, my+1, mx, y2);
	if(mx+1<=x2) play(mx+1, y1, x2, my);
	if(mx+1<=x2 && my+1<=y2) play(mx+1, my+1, x2, y2);
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> n >> m;
	string s;
	for(int i=1;i<=n;i++){
		cin >> s;
		for(int j=1;j<=s.size();j++){
			a[i][j]=s[j-1];
			if(s[j-1]=='1') dp[i][j]++;
			dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		}
	}
	int x1=1,x2=n,y1=1,y2=m;
	play(x1,y1,x2,y2);
	
	return 0;
}
/*
3 4
0010
0001
1011

5 5
10101
00110
11011
10001
00110
DDD1000110DD0110D1011DD1000001D0110
*/
