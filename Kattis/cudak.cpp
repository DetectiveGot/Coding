#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 17, mxS= 137;
ll dp[N][mxS][10];

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	string a,b;
	int s;
	cin >> a >> b >> s;
	int n=a.size(), m=b.size();
	for(int i=0; i<=9; i++) dp[1][i][i]=1;
	for(int i=1; i<=15; i++) {
		for(int d=0; d<=9; d++) {
			for(int j=0; j<=135; j++) {
				for(int k=0; k<=9; k++) {
					dp[i+1][j][d]+=dp[i][j-d][k];
				}
			}
		}
	}
	ll ans=0,sm=0,l,r;
	for(int i=m; i>=1; --i) {
		int d=b[m-i]-'0';
		for(int k=0; k<d; k++) {
			ans+=dp[i][s-sm][k];
		}
		sm+=d;
	}
	if(sm==s) ++ans;
	sm=0;
	ll lt=0;
	for(int i=n; i>=1; --i) {
		int d=a[n-i]-'0';
		for(int k=0; k<d; k++) {
			ans-=dp[i][s-sm][k];
			lt+=dp[i][s-sm][k];
		}
		sm+=d;
	}
	l=r=0;
	for(auto &e:b) r=r*10+e-'0';
	for(auto &e:a) l=l*10+e-'0';
	cout << ans << "\n";
	while(l<r) {
		ll mid = (l+r)/2, cnt=0;
		sm=0;
		b=to_string(mid);
		m=b.size();
		for(int i=m; i>=1; --i) {
			int d=b[m-i]-'0';
			for(int k=0; k<d; k++) {
				cnt+=dp[i][s-sm][k];
			}
			sm+=d;
		}
		if(sm==s) ++cnt;
		sm=0;
		if(cnt-lt<1) l=mid+1;
		else r=mid;
	}
	cout << l;

	return 0;
}
