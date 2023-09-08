#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
int dist[N], from[N];
bool vis[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> g[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,s,t,u,v,w; cin >> n >> m >> s >> t;
	for(int i=0;i<m;i++){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=0;i<n;i++) dist[i]=1e9, from[i]=i;
	dist[s]=0;
	pq.push({dist[s], s});
	while(!pq.empty()){
		int ux=pq.top().second, dx=pq.top().first;
		pq.pop();
		if(vis[ux]) continue;
		vis[ux]=1;
		for(auto&e:g[ux]){
			if(!vis[e.first] && dist[e.first]>dx+e.second){
				dist[e.first]=dx+e.second;
				pq.push({dist[e.first], e.first});
				from[e.first]=ux;
			}
		}
	}
	cout << dist[t] << "\n";
	stack<int> st;
	while(t^from[t]){
		st.push(t);
		t=from[t];
	}
	st.push(t);
	cout << st.size() << "\n";
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
	
	return 0;
}

