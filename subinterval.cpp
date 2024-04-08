#include<bits/stdc++.h>
#define ll long long
#define deb(x,y) cout << #x << ": " << x << " " << #y << ": " << y << "\n"

using namespace std;

const int N = 1e5+2;
ll qs[N], a[N], dp[N], qss[N], qsss[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,q,l,r; cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		qs[i]+=qs[i-1]+a[i];
		qss[i]=qss[i-1]+a[i]*i;
		dp[i]=dp[i-1]+qss[i];
		qsss[i]=qsss[i-1]+qs[i];
	}
	while(q--){
		cin >> l >> r;
		cout << dp[r]-dp[l-1]-(r-l+1)*(qss[l-1])-(l-1)*((qsss[r]-qsss[l-1])-(r-l+1)*qs[l-1]) << "\n";
	}
	
	return 0;
}
