#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 10001;
vector<pii> g[N];
bool vis[N], fire[N];
int dist[N], d2[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc; cin >> tc;
	string s;
	while(tc--){
		int f,n,u,v,w; cin >> f >> n;
		for(int i=1;i<=n;i++){
			dist[i]=INT_MAX, vis[i]=0, fire[i]=0;
			g[i].clear();
		}
		for(int i=0;i<f;i++){
			cin >> u;
			fire[u]=1;
			pq.push({dist[u]=0, u});
		}
		cin.ignore();
		while(getline(cin, s) && s.size()){
			stringstream ss(s);
			ss >> u >> v >> w;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		int ans=INT_MAX;
		while(!pq.empty()){
			int ux=pq.top().second, dx=pq.top().first;
			pq.pop();
			if(vis[ux]) continue;
			vis[ux]=1;
			for(auto &e:g[ux]){
				if(!vis[e.first] && dist[e.first]>dx+e.second){
					dist[e.first]=dx+e.second;
					pq.push({dist[e.first], e.first});
				}
			}
		}
		int p = 1;
		for(int i=1;i<=n;i++){
			if(fire[i]) continue;
			for(int j=1;j<=n;j++) d2[j]=dist[j], vis[j]=0;
			pq.push({d2[i]=0, i});
			int mx=0;
			while(!pq.empty()){
				int ux=pq.top().second, dx=pq.top().first;
				pq.pop();
				if(vis[ux]) continue;
				vis[ux]=1;
				for(auto &e:g[ux]){
					if(!vis[e.first] && d2[e.first]>dx+e.second){
						d2[e.first]=dx+e.second;
						pq.push({d2[e.first], e.first});
					}
				}
			}
			for(int i=1;i<=n;i++) mx=max(mx, d2[i]);
			if(ans>mx) ans=mx, p=i;
		}
		cout << p << "\n";
	}

	return 0;
}

