#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e4+1;
vector<pii> g[N+102];
bool dp[N][N];
// d=1 -> hor, d=2 -> ver

void solve(){
	int n,m,r,t,d,c; cin >> n >> m >> r;
	int lim = n+m+r;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			dp[i][j]=0;
	for(int i=1;i<=lim;i++) g[i].clear();
	for(int i=0;i<r;i++){
		cin >> t >> d >> c;
		if(t>lim) continue;
		g[t].push_back({d,c});
	}
	dp[0][0]=1;
	for(int tm=1;tm<=lim;tm++){
		for(int i=n;i>=0;--i){
			for(int j=m;j>=0;--j){
				if(i) dp[i][j]|=dp[i-1][j];
				if(j) dp[i][j]|=dp[i][j-1];
			}
		}
		for(pii &e:g[tm]){
			if(e.first==1){
				for(int j=0;j<=m;j++) dp[e.second][j]=0;
			} else {
				for(int i=0;i<=n;i++) dp[i][e.second]=0;
			}
		}
		if(dp[n][m]){
			cout << tm << "\n";
			return;
		}
	}
	cout << "-1\n";
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}
