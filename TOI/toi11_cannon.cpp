#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e7+1, lim = 1e7;
int qs[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,k,l,t; cin >> n >> m >> k >> l;
	for(int i=1;i<=n;i++){
		cin >> t;
		qs[t+1]++;
	}
	for(int i=1;i<N;i++) qs[i]+=qs[i-1];
	for(int i=0;i<k;i++){
		int p=0,ans=0;
		for(int j=0;j<m;j++){
			cin >> t, ++t;
			ans+=qs[min(t+l, lim)]-qs[max(t-l-1, p)];
			p=min(t+l, lim);
		}
		cout << ans << "\n";
	}

	return 0;
}
