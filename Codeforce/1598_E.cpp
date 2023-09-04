#include<bits/stdc++.h>
#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

using namespace std;

const int N = 1002;
bool vis[N][N];
int dp[N][N][2],s=0;

void cal(int i, int j){
	s-=dp[i][j][0]+dp[i][j][1];
	if(vis[i][j]) dp[i][j][0]=dp[i][j][1]=0;
	else {
		dp[i][j][1]=dp[i][j-1][0]+1;
		dp[i][j][0]=dp[i-1][j][1]+1;
	}
	s+=dp[i][j][0]+dp[i][j][1];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,q,x,y,cnt=0; cin >> n >> m >> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cal(i,j);
		}
	}
//	deb(s);
	cnt=n*m;
	while(q--){
		cin >> x >> y;
		if(vis[x][y]) cnt++, vis[x][y]=0;
		else cnt--, vis[x][y]=1;
		cal(x,y); ++x, ++y;
		while(x<=n+1 && y<=m+1){
			if(x<=n) cal(x,y-1);
			if(y<=m) cal(x-1, y);
			if(x<=n && y<=m) cal(x,y);
			x++, y++;
		}
		cout << s-cnt << "\n";
	}
	
	return 0;
}
