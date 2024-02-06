#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 41;
int a[N],n;
ll ans=0;

inline void solve(int i, int s){
	if(i>n) return void(ans-=s);
	if(s+a[i]<200) solve(i+1, s+a[i]);
	solve(i+1, s);
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i], ans+=a[i]*1ll<<n-1;
	solve(1, 0);
	cout << ans;

	return 0;
}
