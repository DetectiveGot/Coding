#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

const int N = 2e5+2;
struct DATA{
	int ux, cnt;
};
int vis[N], mon[N];

void solve(){
	int n,m,u,v,st=0; cin >> n >> m;
	vector<int> g[n+1];
	priority_queue<pii, vector<pii>, greater<pii>> q;
	for(int i=1;i<=n;i++){
		vis[i]=0;
		cin >> mon[i];
	}
	while(m--){
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(vis[i] || mon[i]) continue;
		int cnt=0;
		q.push({0, i}); vis[i]=i;
		while(!q.empty()){
			int ux=q.top().second, k=q.top().first;
			q.pop();
			if(k<=cnt){
				// go in first then after that check if the one that goes in works and continue
				cnt++;
				for(auto&e:g[ux]){
					if(vis[e]^i){
						q.push({mon[e], e});
						vis[e]=i;
					}
				}
			}
		}
		if(cnt==n){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}
