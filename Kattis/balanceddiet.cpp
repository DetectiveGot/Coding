#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 12001;
bool dp[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,s=0,t;
	while(cin >> n && n!=0){
		s=0;
		dp[0]=1;
		for(int i=0;i<n;i++){
			cin >> t, s+=t;
			for(int j=s;j>=t;--j) dp[j]|=dp[j-t];
		}
		int mn=INT_MAX,r1=0,r2=0;
		for(int j=1;j<=s;j++) if(dp[j] && abs(2*j-s)<mn) r1=max(j, s-j), r2=min(j, s-j), mn=abs(2*j-s);
		cout << r1 << " " << r2 << "\n";
		memset(dp, 0, sizeof(dp));
	}
	
	return 0;
}
