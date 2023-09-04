#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+2;
const string rep = "xyz";
int x[N], c[N], pa[N];
// pref length, num of sub palin

void solve(){
	int n,k,cnt=0; cin >> n >> k;
	char nxt='a';
	x[0]=c[0]=3;
	for(int i=1;i<=k;i++) cin >> x[i];
	for(int i=1;i<=k;i++) cin >> c[i];
	string ans=rep;
	for(int i=1;i<=k;i++){
		if(x[i]-x[i-1]<c[i]-c[i-1]){
			cout << "NO\n";
			return;
		}
		int add=c[i]-c[i-1], lim=x[i]-x[i-1]-add;
		for(int j=0;j<add;j++) ans+=nxt;
		for(int j=0;j<lim;j++) ans+=rep[(cnt++)%3];
		nxt++;
	}
	cout << "YES\n" << ans << "\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		solve();
	}
	
	return 0;
}
