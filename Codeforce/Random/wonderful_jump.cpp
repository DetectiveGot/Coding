#include<bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const int N = 4e5+2;
ll a[N], dp[N];
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i], dp[i]=1e18;
	dp[1]=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(2*(i-j)-1>n/a[i]) break;
			dp[i]=min(dp[i], dp[j]+a[i]*(j-i)*(j-i));
			if(a[j]<=a[i]) break;
		}
//		for(int j=i+1;j<=n;j++){
//			if(2*(j-i)-1>n/a[i]) break;
//			dp[j]=min(dp[j], dp[i]+a[i]*(j-i)*(j-i));
//			if(a[j]<=a[i]) break;
//		}
	}
	for(int i=1;i<=n;i++) cout << dp[i] << " ";
	cout << "\n";
	
	return 0;
}
