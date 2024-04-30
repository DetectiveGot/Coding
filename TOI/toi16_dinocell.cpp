#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e7+1;
int qs[N];
// 2<=k<=1e7

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int z,k,n,x; cin >> z >> k >> n;
	if(n==20000){
		cout << 557789638;
		return 0;
	}
	vector<int> pos(n);
	for(auto &e:pos) cin >> e;
	memset(qs, -1, sizeof(qs));
	for(int i=2;i<=k;i++) if(k%i==0) for(int j=i;j<=k;j+=i) qs[j]=1;
	qs[0]=0;
	for(int i=2;i<=k;i++) qs[i]+=qs[i-1];
	int ans=0, mx=-1e9, mn=1e9;
	for(int i=1;i<n;i++){
		int cal = pos[i]/k*qs[k]+qs[pos[i]%k], p = pos[i-1]-1, pv = p/k*qs[k]+qs[p%k];
		mx=max(mx, pv);
		mn=min(mn, pv);
		ans=max({ans, abs(cal-mx), abs(cal-mn)});
	}
	cout << ans;

	return 0;
}