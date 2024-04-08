#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << "]: " << x << " "

using namespace std;

const int N = 1e5+2;
ll w[N];
vector<pii> g[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,u,v,d; cin >> n;
	for(int i=1;i<=n;i++) cin >> w[i];
	for(int i=1;i<n;i++){
		cin >> u >> v >> d;
		g[u].push_back({v,d});
		g[v].push_back({u,d});
	}
	
	return 0;
}
