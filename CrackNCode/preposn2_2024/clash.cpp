#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 5001;
int dp[N][8][8][8][8], a[8], b[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i=0; i<8; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];
	memset(dp, -1, sizeof(dp));
	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			if(i==j) continue;
			for(int k=0; k<8; k++) {
				if(k==i || k==j) continue;
				for(int r=0; r<8; r++) {
					if(r==k || r==i || r==j) continue;
					dp[0][i][j][k][r]=0;
				}
			}
		}
	}
	for(int t=0; t<n; t++) {
		for(int i=0; i<8; i++) {
			for(int j=0; j<8; j++) {
				if(i==j) continue;
				for(int k=0; k<8; k++) {
					if(k==i || k==j) continue;
					for(int r=0; r<8; r++) {
						if(r==k || r==i || r==j || dp[t][i][j][k][r]==-1) continue;
						int mx=0;
						for(int q=0; q<8; q++) {
							if(q==i || q==j || q==k || q==r) continue;
							dp[t+1][j][k][r][q]=max(dp[t+1][j][k][r][q], dp[t][i][j][k][r]+abs(a[q]-b[t]));
						}
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			if(i==j) continue;
			for(int k=0; k<8; k++) {
				if(k==i || k==j) continue;
				for(int r=0; r<8; r++) {
					if(r==k || r==i || r==j) continue;
					ans=max(ans, dp[n][i][j][k][r]);
				}
			}
		}
	}
	cout << ans;

	return 0;
}