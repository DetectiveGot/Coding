#include<bits/stdc++.h>

using namespace std;

const int N = 5e5+1;
int qs[N];
bool p[1000005];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,k,t; cin >> n >> k;
	p[1]=1;
	for(int i=2;i<=1000000;i++){
		if(p[i]) continue;
		for(int j=2*i;j<=1000000;j+=i) p[j]=1;
	}
	int ans=1e9;
	for(int i=1;i<=n;i++){
		cin >> t;
		if(!p[t]) qs[i]++;
		qs[i]+=qs[i-1];
		int it = upper_bound(qs+1, qs+i, qs[i]-k)-qs;
		if(qs[i]>=k) ans=min(ans, i-it+1);
	}
	cout << ans;
	
	return 0;
}
