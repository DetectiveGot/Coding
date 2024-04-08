#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
ll w[N],h[N],dp[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc; cin >> tc;
	while(tc--){
		for(int i=1;i<=n;i++) cin >> w[i];
		for(int i=1;i<=n;i++) cin >> h[i];
		dp[0];
		for(int i=1;i<=n;i++){
			int s=0,mx=0;
			for(int j=i;j<=n;j++){
				if(s+w[j]>k) break;
				s+=w[j];
				mx=max(mx, h[j])
				dp[j]=min(dp[j], dp[i-1]+mx);
			}
		}
		cout << dp[n] << "\n";
	}
	
	return 0;
}
