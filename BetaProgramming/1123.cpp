#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 1001;
int dp[N][N], a[N][N], b[N][N];

inline int cal(int &i, int &j, int &k){
	return a[i][j]-a[i][j-k]-a[i-k][j]+a[i-k][j-k];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,k,ans=0; cin >> n >> k;
	for(int r=1;r<=3;r++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin >> a[i][j];
				a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			}
		}
		for(int i=1;i<=n;i++){
			deque<pii> dq;
			for(int j=1;j<=n;j++){
				if(i-k>=0 && j-k>=0){
					b[i][j] = cal(i,j,k);
					while(!dq.empty() && j-dq.front().second>=k) dq.pop_front();
					while(!dq.empty() && b[i][j]>=dq.back().first) dq.pop_back();
					dq.push_back({b[i][j], j});
					b[i][j]=dq.front().first;
				}
			}
		}
		for(int j=1;j<=n;j++){
			deque<pii> dq;
			for(int i=1;i<=n;i++){
				if(i-k>=0 && j-k>=0){
					while(!dq.empty() && i-dq.front().second>=k) dq.pop_front();
					while(!dq.empty() && b[i][j]>=dq.back().first) dq.pop_back();
					dq.push_back({b[i][j], i});
					b[i][j]=dq.front().first;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]+=b[i][j];
				ans=max(ans, dp[i][j]);
//				cout << dp[i][j] << " ";
			}
//			cout << endl;
		}
	}
	cout << ans;
	
	return 0;
}
/*
3 2
1 2 3
4 5 6
7 8 9
1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1

*/
