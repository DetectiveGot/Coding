#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2e5+1;
queue<int> q;
ll dist[N];
vector<int> g[N];
priority_queue<int, vector<int>, greater<int>> pq[26];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,k,u,v; cin >> n >> m >> k;
	string s; cin >> s;
	for(int i=0;i<m;i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	q.push(1); dist[1]=1;
	while(!q.empty()){
		u=q.front();
		q.pop();
		pq[s[u-1]-'A'].push((dist[u]-1)*2);
		for(auto &e:g[u]){
			if(dist[e]) continue;
			q.push(e);
			dist[e]=dist[u]+1;
		}
	}
	string x; cin >> x;
	ll ans=0;
	for(auto &e:x){
		if(pq[e-'A'].empty()){
			cout << -1;
			return 0;
		}
		ans+=pq[e-'A'].top();
		pq[e-'A'].pop();
	}
	cout << ans;
	
	return 0;
}
