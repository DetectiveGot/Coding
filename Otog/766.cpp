#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1, K = 51;
vector<pii> g[N];
int dist[N],ans[N];
bool vis[N];
struct DATA{
	int s,t,idx;
};
vector<DATA> ask[N];
vector<int> res;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(){
	int n,m,k,q,u,v,w,r; scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=0;i<k;i++){
		scanf("%d", &r);
		res.push_back(r);
	}
	int s,x,t;
	for(int i=0;i<q;i++){
		scanf("%d%d%d",&s,&x,&t);
		ask[x].push_back({s,t,i});
	}
	for(auto &b:res){
		for(auto &c:ask[b]){
			for(int j=0;j<n;j++) vis[j]=0, dist[j]=1e9;
			dist[b]=0;
			pq.push({dist[b], b});
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
			ans[c.idx]=dist[c.s]+dist[c.t];
		}
	}
	for(int i=0;i<q;i++) printf("%d\n", ans[i]);
	
	return 0;
}
